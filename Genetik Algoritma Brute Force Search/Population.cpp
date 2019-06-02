#include "Population.h"



Population::Population(std::vector<char> target, int size, float mutation)
{
	_generation = -1;
	_found = false;
	_target = target;
	_mutationRate = mutation;

	for (int i = 0; i < size; i++)
	{
		_individuals.push_back(Individual(target, target.size()));
	}

	Evaluate();
}

void Population::Print()
{
	std::cout << "Generation :" << _generation << std::endl;
	for (int i = 0; i < _individuals.size(); i++)
	{
		std::cout << "Individual " << (i + 1) << ":";
		_individuals.at(i).Print();
	}
}

void Population::CalculateFitness()
{
	for (int i = 0; i < _individuals.size(); i++)
	{
		_individuals.at(i).CalculateFitness(_target);
	}
}

void Population::PopulationSort()
{
	std::sort(_individuals.begin(), _individuals.end(), IndividualCompare());
}

void Population::Evaluate()
{
	CalculateFitness();
	CheckFound();
	Selection();
	CrossOver();
	Mutation();
	CalculateFitness();
	_generation++;
}

void Population::Selection()
{
	std::sort(_individuals.begin(), _individuals.end(), IndividualCompare());

	int size = _individuals.size() / 2;
	for (int i = 0; i < size; i++)
	{
		_individuals.pop_back();
	}
}

void Population::CrossOver()
{
	int geneSize = _target.size();
	int randomRange = geneSize - (_target.size() / 4);
	int crossoverCount = _individuals.size();

	auto selectedPopulation = _individuals;
	auto selectedPopulationSize = selectedPopulation.size();
	for (int i = 0; i < crossoverCount; i++)
	{
		int geneCut = rand() % randomRange + 1;

		int parent1 = rand() % selectedPopulationSize;
		int parent2 = rand() % selectedPopulationSize;

		while (parent2 == parent1)
			parent2 = rand() % selectedPopulationSize;

		auto individual1 = selectedPopulation.at(parent1);
		auto individual2 = selectedPopulation.at(parent2);

		std::vector<char> p1genes, p2genes, children;
		for (int i = 0; i < geneCut; i++)
		{
			p1genes.push_back(individual1.GetGeneAtIndex(i));
		}
		for (int i = geneCut; i < geneSize; i++)
		{
			p2genes.push_back(individual2.GetGeneAtIndex(i));
		}
		children.insert(children.end(), p1genes.begin(), p1genes.end());
		children.insert(children.end(), p2genes.begin(), p2genes.end());

		_individuals.push_back(Individual(children, _target));
	}
}

void Population::Mutation()
{
	int popSize = _individuals.size();
	int geneSize = popSize * _target.size();
	int mutationGeneCount = std::ceil(_mutationRate * geneSize);

	for (int i = 0; i < mutationGeneCount; i++)
	{
		int selectedPopMember = rand() % popSize;
		int selectedGeneIndex = rand() % _target.size();

		_individuals.at(selectedPopMember).Mutate(selectedGeneIndex);
	}
}

void Population::CheckFound()
{
	for (int i = 0; i < _individuals.size(); i++)
	{
		if (_individuals.at(i).GetFitness() == _target.size())
		{
			_found = true;
			break;
		}
	}
}
