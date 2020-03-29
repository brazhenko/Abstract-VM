//
// Created by 17641238 on 29.03.2020.
//

#include <string>
#include <fstream>
#include <iostream>
#include "AVMLexer.h"

void ExecuteInteractive()
{
	std::string line;

	while (line != AVM_EOF_INTERACTIVE)
	{
		getline(std::cin, line);
	}
}

void ExecuteFile(const std::string& fileName)
{
	std::ifstream fs(fileName);
	std::string line;

	if (!fs.is_open() || !fs)
		throw std::runtime_error("Error on opening file : " + fileName);

	for (int lineNum = 1; getline(fs, line); lineNum++)
	{
		std::cout << lineNum << ": " << line << std::endl;
	}
}