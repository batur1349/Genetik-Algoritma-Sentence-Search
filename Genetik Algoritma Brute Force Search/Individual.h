#pragma once
#include <vector>
#include <iostream>
#include <random>

constexpr int _asciiStart = 32;
constexpr int _asciiEnd = 126;

class Individual
{
public:
	Individual(std::vector<char> gene, std::vector<char> target);
	Individual(std::vector<char> target, int size);
	virtual ~Individual();

	void Print();
	void Mutate(int& index);
	void CalculateFitness(std::vector<char> target);

	const int& GetFitness() { return _fitness; }
	const char& GetGeneAtIndex(const int& index) { return _gene.at(index); }
private:
	int _fitness;
	std::vector<char> _gene;
};