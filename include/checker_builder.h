/**
 * checker_builder.h
 *
 * Helper class to build instances of Checker objects.
 */
#pragma once

#include "checker.h"

namespace qvmove {
class CheckerBuilder {
	private:
		typedef std::shared_ptr<std::istream> IPtr;
		typedef std::shared_ptr<std::ostream> OPtr;
		typedef std::vector<std::shared_ptr<cluster::MMIMove>> _MoveVector;
		typedef std::unordered_set<std::shared_ptr<cluster::EquivQuiverMatrix>> _MatrixSet;
	public:
		CheckerBuilder();
		/**
		 * Set the input stream for the Checker. This stream should contain a number
		 * of matrices which will be checked in turn.
		 */
		void input(const std::string& ifile);
		/**
		 * Set the output stream, where results are outputted.
		 */
		void output(const std::string& ofile);
		/**
		 * Set the moves which are used in the checks. By default this is set to be
		 * qvmove::consts::Moves
		 */
		void moves(const _MoveVector& moves);
		/**
		 * Set the class representatives to try and find in the move classes.
		 * By default this is set to be qvmove::consts::Reps.
		 */
		void reps(const _MatrixSet& reps);
		/**
		 * Generate the Checker
		 */
		Checker build();
	private:
		IPtr in_;
		OPtr out_;
		_MoveVector& moves_;
		_MatrixSet& reps_;

		struct NullDeleter {
			void operator()(const void *const) const {}
		};
};
}

