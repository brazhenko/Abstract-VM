//
// Created by 17641238 on 29.03.2020.
//

#ifndef AVM_AVM_H
#define AVM_AVM_H

#include <vector>
#include <string>

namespace AVM
{
	struct Context
	{
		std::vector<std::string> filesToExecute;
		std::vector<std::string> filesToOptimize;

		bool isInteractive;
	};
}

AVM::Context parseAVMArgv(int argc, char **argv);
void ExecuteFile(const std::string& fileName);
void ExecuteInteractive();
std::string getUsage();

#endif //AVM_AVM_H
