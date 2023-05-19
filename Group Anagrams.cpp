#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
private:
    std::multimap<std::string, std::string> map;

public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        
        // map.reserve(strs.size());
        std::vector<std::string> strings;
        std::vector<std::vector<std::string>> finally;

        finally.reserve(10);

        strings.reserve(10);

        std::string copy;

        for (int i = 0; i < strs.size(); i++)
        {
            copy = strs[i];

            std::sort(copy.begin(), copy.end());

            map.emplace(std::move(copy), std::move(strs[i]));
        }

        auto group = map.begin();

        for (auto&[key, value] : map)
        {
            
            if (key == group->first)
                strings.emplace_back(std::move(value));

            else
            {
                finally.emplace_back(std::move(strings));

                strings.clear();

                group = map.find(key);

                strings.emplace_back(std::move(value));
            }
        }

        finally.emplace_back(std::move(strings));

        strings.clear();

        return finally;
    }
};
