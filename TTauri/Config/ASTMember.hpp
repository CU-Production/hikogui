
#pragma once

#include "ASTExpression.hpp"

#include <string>

namespace TTauri::Config {

struct ASTMember : ASTExpression {
    ASTExpression *object;
    std::string name;

    ASTMember(ASTLocation location, ASTExpression *object, char *name) : ASTExpression(location), object(object), name(name) {
        free(name);
    }

    ~ASTMember() {
        delete object;
    }

    std::string str() override {
        return object->str() + "." + name;
    }

    virtual std::shared_ptr<ValueBase> execute(ExecutionContext *context) override { 
        return (*object->execute(context))[name];
    } 

    virtual std::shared_ptr<ValueBase> executeAssignment(ExecutionContext *context, const std::shared_ptr<ValueBase> &other) {
        (*object->execute(context))[name] = other;
        return other;
    }

};

}
