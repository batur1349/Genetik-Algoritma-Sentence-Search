#pragma once
#include "Population.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(const int& popSize, const std::vector<char>& target, const float& mutateRate);

	void Run();
private:
	int _maxIteration, _iteration, _populationSize;
	std::vector<char> _target;
	float _mutationRate;
	Population _population;
};

