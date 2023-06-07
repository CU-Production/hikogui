namespace hi {
inline namespace v1 {

/**
\defgroup layout 2D layout algorithms

Layout algorithms
-----------------

 * `hi::grid_layout`: An algorithm that lays out boxes in rows and colunms.
 * `hi::row_layout`: An algorithm that lays out boxes in a single row.
 * `hi::column_layout`: An algorithm that lays out boxes in a single column.
 * `hi::flex_layout`: An algorithm that lays out boxes next to each other, possibly flowing to a next line.

*/

#include "box_constraints.hpp"
#include "box_shape.hpp"
#include "grid.hpp"
#include "grid_axis.hpp"
#include "grid_cell.hpp"
#include "grid_cell_impl.hpp"
#include "grid_state.hpp"

}}
