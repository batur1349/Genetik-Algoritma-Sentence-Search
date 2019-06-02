#include "GeneticAlgorithm.h"



GeneticAlgorithm::GeneticAlgorithm(const int& popSize, const std::vector<char>& target, const float& mutateRate)
	: _population(Population(target, popSize, mutateRate))
{
	_mutationRate = mutateRate;
	_target = target;
	_populationSize = popSize;

	_population.Print();
	system("PAUSE");
}

void GeneticAlgorithm::Run()
{
	while (!_population.Found())
	{
		_population.Evaluate();

		if (_population.Found())
		{
			system("CLS");
			_population.PopulationSort();
			_population.Print();
			break;
		}

		//if (_iteration % (int)(100 * std::ceil(_target.size() / 2)) == 0)
		//{
		if (_iteration % 10 == 0)
		{
			system("CLS");
			_population.Print();
		}
		//}

		_iteration++;
	}
}
