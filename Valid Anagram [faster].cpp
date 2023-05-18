#include <iostream>
#include <future>
#include <map>

class Solution {
public:

    bool isAnagram(std::string& first, std::string& second)
    {

        if (first.size() != second.size())
            return 0;

        else
        {

            std::sort(first.begin(), first.end());

            std::sort(second.begin(), second.end());

            int i = 0;

            for (; i < first.size() && first[i] == second[i]; i++)
            {

            }

            if (i != first.size())
                return 0;

            return 1;
        }

    }
};
