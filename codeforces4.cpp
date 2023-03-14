// If this problem on codeforces https://codeforces.com/contest/2/problem/A required the maximum points to be EXACTLY equal to "m" and not AT LEAST "m", this code would have 
// got accepted.
#include <iostream>
#include <algorithm>
// #include <vector>
#include <unordered_map>
#include <string>

// UPDATE 2:05 PM, 14/3/2023. This code is actually very bad.
bool comparetor(std::pair<const std::string, int>& a, std::pair<const std::string, int>& b)
{
    return a.second < b.second;
}

int main()
{

    std::pair<std::string, int> answer;

    int temp;

    std::string txt;

    std::unordered_map<std::string, int> mp;

    int rounds;

    std::cin >> rounds;

    std::cin.ignore();
    for (int i = 0; i < rounds; i++)
    {

        std::getline(std::cin, txt);

        if (mp.find(txt.substr(0, txt.find(' '))) == mp.end() && mp.size() != 0)
        {

            if (std::stoi(txt.substr(txt.find(' ') + 1, txt.size())) > std::max_element(mp.begin(), mp.end(), comparetor)->second)
            {
                answer.first = txt.substr(0, txt.find(' '));
                answer.second = std::stoi(txt.substr(txt.find(' ') + 1, txt.size()));
                mp.insert(answer);
            }

            else
                mp.insert(std::pair<std::string, int>(txt.substr(0, txt.find(' ')), std::stoi(txt.substr(txt.find(' ') + 1, txt.size()))));
        }

        else if (mp.find(txt.substr(0, txt.find(' '))) != mp.end())
        {
            if (mp.find(txt.substr(0, txt.find(' ')))->first != std::max_element(mp.begin(), mp.end(), comparetor)->first)
            {
                temp = std::stoi(txt.substr(txt.find(' ') + 1, txt.size())) + mp.find(txt.substr(0, txt.find(' ')))->second;

                if (temp > std::max_element(mp.begin(), mp.end(), comparetor)->second)
                {
                    mp.find(txt.substr(0, txt.find(' ')))->second += std::stoi(txt.substr(txt.find(' ') + 1, txt.size()));
                    answer.first = txt.substr(0, txt.find(' '));
                    answer.second = std::stoi(txt.substr(txt.find(' ') + 1, txt.size()));
                }

                else
                    mp.find(txt.substr(0, txt.find(' ')))->second += std::stoi(txt.substr(txt.find(' ') + 1, txt.size()));
            }

            else
            {
                mp.find(txt.substr(0, txt.find(' ')))->second += std::stoi(txt.substr(txt.find(' ') + 1, txt.size()));

                temp = mp.find(txt.substr(0, txt.find(' ')))->second;
                if (temp == std::max_element(mp.begin(), mp.end(), comparetor)->second)
                    answer.second += std::stoi(txt.substr(txt.find(' ') + 1, txt.size()));

                else
                {
                    answer.first = std::max_element(mp.begin(), mp.end(), comparetor)->first;
                    answer.second = std::max_element(mp.begin(), mp.end(), comparetor)->second;
                }
            }
        }

        else
        {
            answer.first = txt.substr(0, txt.find(' '));
            answer.second = std::stoi(txt.substr(txt.find(' ') + 1, txt.size()));
            mp.insert(answer);
        }
    }

    std::cout << answer.first << std::endl;
}
