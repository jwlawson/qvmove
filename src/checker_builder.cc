/**
 * checker_builder.cc
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
 * Builds a Checker object.
 *
 * Moves, matrices and graphs can be specified, otherwise the default is to use
 * those in consts.cc
 */
#include "checker_builder.h"

#include <iostream> /* Needed for stdin and stdout */
#include <fstream>

#include "consts.h"

namespace qvmove {

	CheckerBuilder::CheckerBuilder() : 
		in_(), 
		out_(),
		moves_(qvmove::consts::Moves), 
		reps_(qvmove::consts::Reps),
		graphs_(qvmove::consts::Graphs) {}
	void CheckerBuilder::input(const std::string& ifile) {
		if(ifile.empty()) {
			in_ = IPtr(&std::cin, NullDeleter());
		} else {
			std::ifstream* file = new std::ifstream(ifile);
			if(!file->is_open()) {
				std::cerr << "Error opening file " << ifile << std::endl;
				delete file;
				exit(2);
			}
			in_ = IPtr(file);
		}
	}
	void CheckerBuilder::output(const std::string& ofile) {
		if(ofile.empty()) {
			out_ = OPtr(&std::cout, NullDeleter());
		} else {
			std::ofstream* file = new std::ofstream(ofile);
			if(!file->is_open()) {
				std::cerr << "Error opening file " << ofile << std::endl;
				delete file;
				exit(2);
			}
			out_ = OPtr(file);
		}
	}
	void CheckerBuilder::moves(const _MoveVector& moves) {
		moves_ = moves;
	}
	void CheckerBuilder::reps(const _MatrixSet& reps) {
		reps_ = reps;
	}
	void CheckerBuilder::graphs(const _GraphSet& graphs) {
		graphs_ = graphs;
	}
	Checker CheckerBuilder::build() {
		Checker result(in_, out_, moves_, reps_, graphs_);
		return std::move(result);
	}
}

