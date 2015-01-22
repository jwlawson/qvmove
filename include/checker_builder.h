/**
 * checker_builder.h
 * Copyright 2014-2015 John Lawson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
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
		typedef std::unordered_set<std::shared_ptr<cluster::EquivUnderlyingGraph>> _GraphSet;
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
		void graphs(const _GraphSet& graphs);
		/**
		 * Generate the Checker
		 */
		Checker build();
	private:
		IPtr in_;
		OPtr out_;
		_MoveVector& moves_;
		_MatrixSet& reps_;
		_GraphSet& graphs_;

		struct NullDeleter {
			void operator()(const void *const) const {}
		};
};
}

