# include <vector>
# include <iostream>
# include <unordered_map>

using namespace std;


class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans = {};
        vector<int> subset = {};
        // nums[0] will be at the first layer the recursive process, and nums[-1] will be at the last layer
        // dfs() will execute recrusivly toward the last layer first, which is the nums.size() th layer
        // Starting with add all numbers to the subset, then pushback the subset into the ans
        // After that, the execution step back to the previous layer, then go to the last layer again, but pop back nums[-1] from the subset this time
        // After losing the nums[-1], the subset are pushback into the ans again
        // Afterward, the execution step back to the 2nd previous layer and then go through the last 2 layers again, this time nums[-2] is poped back from subset
        // ... ...
        // Done with nums[-2], now is time to exclude nums[-3]
        // ... ...
        dfs(0, nums, ans, subset);
        return ans;
    }

    void dfs(int idx_layers, const vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset) // using '&' (assign address) to make sure the only ans and subset are the ones edited
    {
        if (idx_layers >= nums.size())
        {
            ans.push_back(subset);
            return;
        }
        // First, find all possible sets including nums[idx_layers]
        // Add the number (nums[idx_layer]) to the subset
        subset.push_back(nums[idx_layers]);
        dfs(idx_layers+1, nums, ans, subset); 
        // Done with adding nums[idx_layers] to the subset, now is time to get sets excluding nums[idx_layers] from the subset
        // Pop back the number (nums[idx_layer]) from the subset
        subset.pop_back();
        dfs(idx_layers+1, nums, ans, subset);
    }
};

int main(void)
{
    Solution func;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = func.subsets(nums);
    return 0;
   
}