#pragma once
#include "Individual.h"
#include <vector>
#include <algorithm>

struct IndividualCompare
{
	bool operator()(Individual& a, Individual& b) const { return a.GetFitness() > b.GetFitness(); }
};

class Population
{
public:
	Population(std::vector<char> target, int size, float mutation);

	void Print();
	void CalculateFitness();
	void PopulationSort();
	void Evaluate();

	bool Found() { return _found; }
private:
	// Container
	std::vector<char> _target;
	std::vector<Individual> _individuals;
	int _totalFitness, _generation;
	float _mutationRate;
	bool _found;

	void Selection();
	void CrossOver();
	void Mutation();
	void CheckFound();
};

