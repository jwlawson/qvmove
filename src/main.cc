/**
 * main.cc
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
 * Main function for checking that the list of moves will classify all mmi
 * quivers. Takes an input stream of quivers (either stdin or a file) and for
 * each matrix in the stream checks whether the moves will tranform that matrix
 * into one of the specified representatives. The number of moves required will
 * then be printed out along with the matrix as the output.
 */
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

#include "checker_builder.h"
#include "consts.h"

void usage() {
	std::cout << "qvmove [-i input] [-o output]" << std::endl;
}

int main(int argc, char *argv[]) {
	std::string ifile;
	std::string ofile;
	int c;
	while ((c = getopt (argc, argv, "i:o:")) != -1) {
		switch (c){
			case 'i':
				ifile = optarg;
				break;
			case 'o':
				ofile = optarg;
				break;
			case '?':
				usage();
				return 1;
			default:
				usage();
				return 2;
		}
	}
	qvmove::CheckerBuilder builder;
	builder.input(ifile);
	builder.output(ofile);

	qvmove::Checker check(builder.build());

	check.run();
	return 0;
}

