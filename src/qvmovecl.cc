/**
 * qvmovecl.cc
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
 * Program to calculate all matrices in a given move class.
 */
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

#include "qv/move_class_loader.h"

#include "consts.h"

void usage() {
	std::cout << "qvmove -m matrix" << std::endl;
}

int main(int argc, char *argv[]) {
	std::string matrix;
	int c;
	while ((c = getopt (argc, argv, "m:")) != -1) {
		switch (c){
			case 'm':
				matrix = optarg;
				break;
			case '?':
				usage();
				return 1;
			default:
				usage();
				return 2;
		}
	}
	if(matrix.empty()) {
		usage();
		return 1;
	}
	std::shared_ptr<cluster::EquivQuiverMatrix>
		m = std::make_shared<cluster::EquivQuiverMatrix>(matrix);
	cluster::MoveClassLoader loader(m, qvmove::consts::Moves);
	while(loader.has_next()){
		auto matrix = loader.next();
		std::cout << *matrix << std::cout.widen('\n');
	}
	std::cout.flush();
	return 0;
}
