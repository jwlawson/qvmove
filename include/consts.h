/**
 * consts.h
 *
 * Header containing declarations of constants to use in qvmove.
 */
#pragma once

#include <memory>
#include <vector>
#include <unordered_set>

#include "qv/equiv_quiver_matrix.h"
#include "qv/equiv_underlying_graph.h"
#include "qv/mmi_move.h"

namespace qvmove {
namespace consts {

extern std::vector<std::shared_ptr<cluster::MMIMove>> Moves;
extern std::unordered_set<std::shared_ptr<cluster::EquivQuiverMatrix>> Reps;
extern std::unordered_set<std::shared_ptr<cluster::EquivUnderlyingGraph>> Graphs;

}
}

