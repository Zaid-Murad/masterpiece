#include <iostream>
#include <future>
#include <map>

class Solution {

private:
    std::map<char, int> BuildHash(const std::string& keys)
    {
        std::map<char, int> mp;

        auto key = mp.begin();

        for (int i = 0; i < keys.size(); i++)
        {
            key = mp.find(keys[i]);

            if (key == mp.end())
                mp[keys[i]] = 0;

            else
                key->second++;
        }

        return mp;
    }

public:
    bool isAnagram(std::string& first, std::string& second)
    {

        if (first.size() != second.size())
            return 0;

        else
        {

            std::future<std::map<char, int>> FirstHash = std::async(std::launch::async, [&first, this] {
                return this->BuildHash(first);
                });


            std::future<std::map<char, int>> SecondHash = std::async(std::launch::async, [&second, this] {
                return this->BuildHash(second);
                });

            const auto& mp = FirstHash.get();

            const auto& mp2 = SecondHash.get();

            auto iter = mp.begin();

            auto iter2 = mp2.begin();

            for (int i = 0; i < mp.size(); i++)
            {
                if (iter->first == iter2->first)
                {
                    ++iter;
                    ++iter2;
                }

                else
                {
                    return 0;
                }
            }

            iter = mp.begin();

            iter2 = mp2.begin();

            for (int i = 0; i < mp.size(); i++)
            {
                if (iter->second == iter2->second)
                {
                    ++iter;
                    ++iter2;
                }

                else
                {
                    return 0;
                }
            }

            return 1;

        }

    }
};
