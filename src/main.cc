/**
 * main.cc
 *
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

	qvmove::Checker check = builder.build();

	check.run();
	return 0;
}

