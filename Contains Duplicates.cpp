#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
private:
    std::unordered_set<int> hash;

public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        bool changed = 1;
        int size = 0;
        int i = 0;
        for (; i < nums.size() && changed; i++)
        {
            size = hash.size();
            hash.insert(nums[i]);

            changed = hash.size() - size != 0;
        }

        if (changed)
            return 0;

        return 1;
    }
};
