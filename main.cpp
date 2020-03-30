#include <iostream>
#include <Exceptions/AVMException.h>
#include "Service/AVM.h"

int main(int argc, char **argv)
{

	AVM::Context context;

	try {
		context = parseAVMArgv(argc, argv);
	}
	catch (AVM::OptionRequiresAnArguement &e) {
		std::cerr << e.what() << std::endl;
		std::cerr << getUsage() << std::endl;
		return EXIT_FAILURE;
	}
	catch (AVM::NeedHelp&) {
		std::cerr << getUsage() << std::endl;
		return EXIT_FAILURE;
	}
	catch (AVM::UnknownOption &e) {
		std::cerr << e.what() << std::endl;
		std::cerr << getUsage() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...) {
		std::cerr << "Unknown exception" << std::endl;
		return EXIT_FAILURE;
	}

	if (context.filesToExecute.empty())
	{
		try {
			ExecuteInteractive();
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return EXIT_FAILURE;
		}
		catch (...) {
			std::cerr << "Unknown exception" << std::endl;
			return EXIT_FAILURE;
		}
	}

	for (const auto& f : context.filesToExecute)
	{
		try {
			ExecuteFile(f);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return EXIT_FAILURE;
		}
		catch (...) {
			std::cerr << "Unknown exception" << std::endl;
			return EXIT_FAILURE;
		}
	}
	return 0;
}