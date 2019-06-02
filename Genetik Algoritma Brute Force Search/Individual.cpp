#include "Individual.h"



Individual::Individual(std::vector<char> gene, std::vector<char> target)
{
	_fitness = 0;
	_gene = gene;

	CalculateFitness(target);
}

Individual::Individual(std::vector<char> target, int size)
{
	_fitness = 0;

	for (int i = 0; i < size; i++)
	{
		//_gene.emplace_back(rand() % 256);
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(_asciiStart, _asciiEnd);

		_gene.emplace_back(dis(gen));
	}

	CalculateFitness(target);
}

Individual::~Individual()
{

}

void Individual::Print()
{
	std::cout << "Gene :";
	for (int i = 0; i < _gene.size(); i++)
	{
		std::cout << _gene.at(i);
	}
	std::cout << " | Fit :" << _fitness << std::endl;
}

void Individual::Mutate(int& index)
{
	//_gene.at(index) = rand() % 256;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(_asciiStart, _asciiEnd);

	_gene.at(index) = dis(gen);
}

void Individual::CalculateFitness(const std::vector<char> target)
{
	_fitness = 0;

	for (int i = 0; i < target.size(); i++)
	{
		if (target.at(i) == _gene.at(i))
		{
			_fitness++;
		}
	}
}