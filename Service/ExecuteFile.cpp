//
// Created by 17641238 on 29.03.2020.
//

#include <string>
#include <fstream>
#include <iostream>
#include "AVMLexer.h"
#include "StackMachine.h"

void ExecuteInteractive()
{
	std::string line;

	while (line != AVM_EOF_INTERACTIVE)
	{
		getline(std::cin, line);
	}
}

int yyparse();
void ExecuteFile(const std::string& fileName)
{
	std::ifstream fs(fileName);
	std::string line;

	extern FILE * yyin;
	FILE *f = fopen(fileName.c_str(), "r");


	if (!f)
		throw std::runtime_error("Error on opening file : " + fileName);

	yyin = f;
	yyparse();
	fclose(f);
	StackMachine::Instance().Execute();
}