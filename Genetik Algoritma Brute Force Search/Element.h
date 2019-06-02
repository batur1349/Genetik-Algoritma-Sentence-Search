#pragma once
#include <vector>
#include <iostream>

class Individual
{
public:
	Individual(int size);
private:
	std::vector<char> _gene;
};

