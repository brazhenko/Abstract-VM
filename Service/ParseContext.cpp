//
// Created by 17641238 on 29.03.2020.
//

#include <iostream>
#include <fstream>
#include "AVM.h"
#include <getopt.h>
#include "Exceptions/AVMException.h"

AVM::Context parseAVMArgv(int argc, char **argv)
{
	AVM::Context ret;

	ret.isInteractive = true;
	int c;
	opterr = 0;

	while ((c = getopt (argc, argv, "ho:")) != -1)
	{
		switch (c)
		{
		case 'o':
			ret.isInteractive = false;
			ret.filesToOptimize.emplace_back(optarg);
			break;
		case 'h':
			throw AVM::NeedHelp();
		case '?':
			if (optopt == 'o')
				throw AVM::OptionRequiresAnArguement((char)optopt);
			else
				throw AVM::UnknownOption(optopt);
		default:
			abort();
		}
	}

	for (int index = optind; index < argc; index++)
	{
		ret.isInteractive = false;
		ret.filesToExecute.emplace_back(argv[index]);
	}

	std::cerr << "DEBUG" << std::endl;
	for (const auto& f: ret.filesToOptimize)
	{
		std::cerr<< f << " ";
	}
	std::cerr << std::endl;
	for (const auto& f: ret.filesToExecute)
	{
		std::cerr << f << " ";
	}
	std::cerr << std::endl;

	return ret;

}