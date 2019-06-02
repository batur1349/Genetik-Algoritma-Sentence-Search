#include <time.h>
#include <vector>
#include <iostream>
#include <string>

#include "GeneticAlgorithm.h"

int main()
{
	srand(time(NULL));

	std::string targetString = "";

	std::cout << "Enter the target sentence :";
	std::getline(std::cin, targetString);
	std::vector<char> target(targetString.begin(), targetString.end());

	GeneticAlgorithm ga(40, target, 0.01f);
	ga.Run();
	std::cout << "Found the target sentence!" << std::endl;
}