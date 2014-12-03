/**
 * checker_builder.cc
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
		reps_(qvmove::consts::Reps) {}
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
	Checker CheckerBuilder::build() {
		Checker result(in_, out_, moves_, reps_);
		return std::move(result);
	}
}

