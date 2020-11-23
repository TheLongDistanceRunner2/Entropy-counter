#include "pch.h"
#include <iostream>
#include <string>
#include<map>
using namespace std;

const int symbolsNumber = 10;
map<char, double> _map;
map<char, double> _probabilitiesMap;
double _probabilitiesTab[symbolsNumber];

int main()
{
	cout << "Enter a word:" << endl;
	string input;
	cin >> input;


	for (char i = 0; i < input.size(); i++)
	{
		char c = input.at(i);

		// if the map doesn't contain such character:
		if (_map.count(c) == 0)
		{
			// add it to the map:
			_map.insert(std::pair<char, double>(c, 1.0));
		}
		else
		{
			// increase counter:
			_map[c]++;
		}
	}

	cout << "================" << endl;
	for (auto it = _map.cbegin(); it != _map.cend(); ++it)
	{
		std::cout << it->first << " " << it->second << " " << "\n";
	}
	cout << "================" << endl << endl;

	//===================================================
	// count probabilities:
	cout << "Probabilities:" << endl;

	cout << "================" << endl;
	for (auto i : _map)
	{
		_probabilitiesMap[i.first] = (double)i.second / input.size();
		cout << _probabilitiesMap[i.first] << endl;
	}

	double entropy = 0.0;

	// count entropy:
	for (auto i : _probabilitiesMap)
	{
		double tmp = log2(1 / i.second);
		entropy += i.second * tmp;
	}

	cout << endl << "entropy: " << entropy << endl << endl;
}



