//
// Created by 17641238 on 29.03.2020.
//

#include <string>
#include <fstream>
#include <iostream>
#include <Exceptions/AVMException.h>
#include "StackMachine.h"

int yyparse();
extern FILE * yyin;

void ExecuteInteractive()
{
	try
	{
		yyin = stdin;
		yyparse();
	}
	catch (AVM::DoubleSemiColonFound&)
	{}

	StackMachine::Instance().Execute();
}

void ExecuteFile(const std::string& fileName)
{
	std::ifstream fs(fileName);
	std::string line;


	FILE *f = fopen(fileName.c_str(), "r");
	if (!f)
		throw std::runtime_error("Error on opening file : " + fileName);

	yyin = f;
	yyparse();
	fclose(f);
	StackMachine::Instance().Execute();
}

