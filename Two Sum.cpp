#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <optional>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {

        std::unordered_multimap<std::optional<int>, int> umap;

        umap.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++)
            umap.emplace(nums[i], i);

        std::sort(nums.begin(), nums.end());

        bool found = 1;
        int i = 0;
        int x = 0;

        for (; i < nums.size() && found; i++)
        {

            for (x = i + 1; x < nums.size() && found; x++)
                found = nums[i] + nums[x] != target;

        }

        --i;
        --x;

        return
        {
            [&]() mutable
            {
                auto node = umap.extract(nums[i]);
                node.key() = std::nullopt;
                umap.insert(std::move(node));
                return umap.find(std::nullopt)->second;
            }(),

            umap.find(nums[x])->second
        };
    }
};
