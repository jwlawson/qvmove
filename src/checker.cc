/**
 * checker.cc
 */
#include "checker.h"

namespace qvmove {

Checker::Checker(InPtr input, OutPtr output,
		const std::vector<MovePtr>& moves,
		const MatrixSet& reps)
	: iter_(*input),
		input_(input),
		output_(output),
		moves_(moves),
		loader_(nullptr),
		reps_(reps) {}

void Checker::run() {
	while(iter_.has_next()) {
		MatrixPtr init = iter_.next();
		loader_ = LoaderPtr(new cluster::MoveClassLoader(init, moves_));
		bool found = false;
		while(loader_->has_next()) {
			MatrixPtr next = loader_->next();
			if(reps_.find(next) != reps_.end()) {
				/* Is a class representative */
				*output_ << loader_->depth().moves_ << "("<<
					loader_->depth().sinksource_<< "): " << *init << std::endl;
				found = true;
				break;
			}
		}
		if(!found) {
			*output_ << "None: " << *init << std::endl;
		}
	}
}

}

