#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {

        std::multimap<int, int> umap;

        bool found = 0;

        int val = 0;

        auto iter = umap.begin();

        int i = 0;

        for (; i < nums.size(); i++)
        {
            val = target - nums[i];

            iter = umap.find(val);

            found = iter != umap.end();
            
            if (found)
                return { iter->second, i };

            umap.emplace(nums[i], i);
        }

        return { 0, 0 };
    }
};
