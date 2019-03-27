//
//  Device.cpp
//  TTauri
//
//  Created by Tjienta Vara on 2019-02-04.
//  Copyright © 2019 Pokitec. All rights reserved.
//

#include "Instance.hpp"

#include "vulkan_utils.hpp"

#include "TTauri/Logging.hpp"

#include "TTauri/Application.hpp"

#include <chrono>

namespace TTauri {
namespace GUI {

using namespace std;
using namespace gsl;

std::shared_ptr<Instance> Instance::singleton = nullptr;

Instance::Instance()
{
    maintanceThread = thread(Instance::maintenanceLoop, not_null<Instance *>(this));
}

Instance::~Instance()
{
    try {
        [[gsl::suppress(f.6)]] {
            stopMaintenance = true;
            maintanceThread.join();
        }
    } catch (...) {
        abort();
    }
}

void Instance::initialize()
{
    std::scoped_lock lock(mutex);
}

void Instance::setPreferedDevice(boost::uuids::uuid deviceUUID)
{
    std::scoped_lock lock(mutex);
}

shared_ptr<Device> Instance::findBestDeviceForWindow(const shared_ptr<Window> &window)
{
    int bestScore = -1;
    shared_ptr<Device> bestDevice;

    std::scoped_lock lock(mutex);

    for (auto const &device : devices) {
        auto const score = device->score(window);
        LOG_INFO("Device has score=%i.") % score;

        if (score >= bestScore) {
            bestScore = score;
            bestDevice = device;
        }
    }

    switch (bestScore) {
    case -1:
        return nullptr;
    case 0:
        fprintf(stderr, "Could not really find a device that can present this window.");
        /* FALLTHROUGH */
    default:
        return bestDevice;
    }
}

void Instance::add(shared_ptr<Window> window)
{
    std::scoped_lock lock(mutex);

    auto device = findBestDeviceForWindow(window);
    if (!device) {
        BOOST_THROW_EXCEPTION(ErrorNoDeviceForWindow());
    }

    device->add(window);
}

size_t Instance::getNumberOfWindows()
{
    std::scoped_lock lock(mutex);

    size_t numberOfWindows = 0;
    for (const auto &device: devices) {
        numberOfWindows+= device->windows.size();
    }

    return numberOfWindows;
}

bool Instance::updateAndRender(uint64_t nowTimestamp, uint64_t outputTimestamp, bool blockOnVSync)
{
    vector<shared_ptr<Device>> tmpDevices;
    {
        scoped_lock lock(mutex);
        tmpDevices = devices;
    }

    auto hasBlockedOnVSync = false;
    for (auto device : tmpDevices) {
        hasBlockedOnVSync |= device->updateAndRender(nowTimestamp, outputTimestamp, blockOnVSync && !hasBlockedOnVSync);
    }
    return hasBlockedOnVSync;
}

void Instance::maintenance()
{

    vector<shared_ptr<Device>> tmpDevices;
    {
        scoped_lock lock(mutex);
        tmpDevices = devices;
    }

    // Check how many windows are still open.
    auto numberOfOpenWindowsBefore = getNumberOfWindows();

    for (auto device : tmpDevices) {
        auto orphanWindow = device->maintance();
    }

    // Check how many windows are still open.
    auto numberOfOpenWindowsAfter = getNumberOfWindows();

    if (numberOfOpenWindowsAfter == 0 && numberOfOpenWindowsBefore > 0) {
        get_singleton<Application>()->lastWindowClosed();
    }
}

void Instance::maintenanceLoop(gsl::not_null<Instance *> self)
{
    while (!self->stopMaintenance) {
        std::this_thread::sleep_for(std::chrono::milliseconds(67));
        self->maintenance();
    }
}

}}
