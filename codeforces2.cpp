#include <iostream>
#include <vector>
#include <string>
// #include <boost/lexical_cast.hpp>

void add(std::vector<std::vector<bool>>& vec, std::string& first, std::string& second)
{
	bool digit;

	for (int x = 0; x < first.size(); x++)
	{
		std::string s(1, first[x]);
		digit = (bool)(std::stoi(s));
		vec[0].push_back(digit);
	}


	for (int x = 0; x < second.size(); x++)
	{
		std::string s(1, second[x]);
		digit = (bool)(std::stoi(s));
		vec[1].push_back(digit);
	}

}

int main()
{

	std::vector<std::vector<bool>> vec(2);
	std::string first;
	std::string second;

	std::cin >> first >> second;

	add(vec, first, second);

	
	for (int i = 0; i < vec[0].size(); i++)
		std::cout << !((vec[0][i] && vec[1][i]) || (!vec[0][i] && !vec[1][i]));
	

}
