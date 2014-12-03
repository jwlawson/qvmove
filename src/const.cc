/**
 * consts.cc
 */
#include "consts.h"

namespace qvmove {
namespace consts {

namespace {
	std::shared_ptr<cluster::MMIMove> make_move(const std::string& a,
			const std::string& b, std::initializer_list<int> c,
			std::initializer_list<cluster::MMIMove::ConnReq> r) {
		return std::make_shared<cluster::MMIMove>(
				cluster::IntMatrix(a), cluster::IntMatrix(b),
				std::vector<int>(c), std::vector<cluster::MMIMove::ConnReq>(r));
	}
	std::shared_ptr<cluster::EquivQuiverMatrix> matrix(const std::string& a) {
		return std::make_shared<cluster::EquivQuiverMatrix>(a);
	}
}
using namespace cluster::mmi_conn;

std::vector<std::shared_ptr<cluster::MMIMove>> Moves = {
};

std::unordered_set<std::shared_ptr<cluster::EquivQuiverMatrix>> Reps = {
	/* 4 x 4 Hyperbolic coxeter diagram orientations */
	matrix("{ { 0 1 0 0 } { -1 0 1 1 } { 0 -1 0 1 } { 0 -1 -1 0 } }"),
	matrix("{ { 0 1 1 -1 } { -1 0 -1 0 } { -1 1 0 -1 } { 1 0 1 0 } }"),
	matrix("{ { 0 1 1 1 } { -1 0 -1 0 } { -1 1 0 -1 } { -1 0 1 0 } }"),
	matrix("{ { 0 1 1 1 } { -1 0 -1 1 } { -1 1 0 1 } { -1 -1 -1 0 } }"),
	matrix("{ { 0 1 1 -1 } { -1 0 -1 1 } { -1 1 0 1 } { 1 -1 -1 0 } }"),
	matrix("{ { 0 1 1 1 } { -1 0 1 -1 } { -1 -1 0 1 } { -1 1 -1 0 } }")
};

}
}
