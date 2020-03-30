//
// Created by 17641238 on 30.03.2020.
//

#include "AVM.h"

std::string getUsage()
{
	std::string ret
	(
	"Usage: "
   	"AVM [-o file.avm] ... [file2.avm] ...\n"
	"\t-o\t\tOptimize file to minimum operations possible.\n"
	""
	""
	"");

	return ret;
}