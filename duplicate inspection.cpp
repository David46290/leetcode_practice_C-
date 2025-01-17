# include <string>
# include <map>
# include <algorithm>
# include <vector>
# include <iostream>
# include <unordered_set>
using namespace std;
using std::map;
using std::vector;
using std::unordered_set;


class Solution1 // Brute Force: Time O(n^2) | Space O(1)
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        for (int current_idx=0; current_idx<nums.size(); current_idx++)
        {
            for (int match_idx=current_idx+1; match_idx<nums.size(); match_idx++)
            {
                if (nums[current_idx] == nums[match_idx])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution2 // Sort => Check adjacent: Time O(nlogn) | Space O(1)
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        int nums_len = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int current_idx=0; current_idx<nums_len; current_idx++)
        {
            if (nums[current_idx+1] == nums[current_idx])
            {
                return true;
            }
            
        }
        return false;
    }
};

class Solution3 // Build Hash Set to Store Existed Number, Then Check If It Shows Out Again: Time O(n) | Space O(n)  
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        int nums_len = nums.size();
        unordered_set<int> hash_set;
        std::sort(nums.begin(), nums.end());
        for (int current_idx=0; current_idx<nums_len; current_idx++)
        {
            if (hash_set.count(nums[current_idx]) == 1)
            {
                return true;
            }
            else
            {
                hash_set.insert(nums[current_idx]);
            }
              
        }
        return false;
    }
};

int main(void)
{
    Solution3 func;
    vector<int> nums = {1, 2, 3, 1};
    bool result = func.hasDuplicate(nums);
    if (result)
    {
        cout << "Has Duplicate" << endl;
    }
    else
    {
        cout << "No Duplicate" << endl;
    }
    
    return 0;
}