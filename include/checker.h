/**
 * checker.h
 *
 * Contains Checker class which performs the checks on an input stream of
 * quivers and outputs the number of moves required to take each quiver to a
 * class representative.
 */
#pragma once

#include <unordered_set>

#include "qv/stream_iterator.h"
#include "qv/equiv_quiver_matrix.h"
#include "qv/equiv_underlying_graph.h"
#include "qv/move_class_loader.h"

namespace qvmove {
class Checker {
	private:
		typedef std::shared_ptr<std::istream> InPtr;
		typedef std::shared_ptr<std::ostream> OutPtr;
		typedef std::shared_ptr<cluster::MMIMove> MovePtr;
		typedef cluster::EquivQuiverMatrix Matrix;
		typedef std::shared_ptr<Matrix> MatrixPtr;
		typedef std::unordered_set<MatrixPtr> MatrixSet;
		typedef cluster::EquivUnderlyingGraph Graph;
		typedef std::shared_ptr<Graph> GraphPtr;
		typedef std::unordered_set<GraphPtr> GraphSet;
		typedef std::unique_ptr<cluster::MoveClassLoader> LoaderPtr;
	public:
		Checker(InPtr input, OutPtr output,
				const std::vector<MovePtr>& moves,
				const MatrixSet& reps, const GraphSet& graphs);
		Checker(Checker& check) = delete;
		Checker(Checker&& check) = default;
		void run();
	private:
		cluster::StreamIterator<Matrix> iter_;
		InPtr input_;
		OutPtr output_;
		const std::vector<MovePtr>& moves_;
		LoaderPtr loader_;
		const MatrixSet& reps_;
		const GraphSet& graphs_;
		GraphPtr tmp_graph_;
};
}

