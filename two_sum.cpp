# include <map>
# include <algorithm>
# include <vector>
# include <iostream>
# include <unordered_set>
using namespace std;
using std::map;
using std::vector;
using std::unordered_set;

class Solution1 // Brute Force: O(n^2)
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            int residual = 0;
            for (int i=0; i<nums.size(); i++)
            {
                residual = target - nums[i];
                for (int j=i+1; j<nums.size(); j++)
                {
                    if (nums[j]==residual)
                    {
                        return {i, j};
                    }

                }
            }
            return {0, 0};
        }
};

class Solution2 // Use Hashmap to check wether residual already exist in current map O(n) in both time & space
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            map<int, int> nums_map; // start w/ empty map
            int residual = 0;
            for (int i=0; i<nums.size(); i++)
            {
                residual = target - nums[i];
                //nums_map.insert(std::pair<int,int>(nums[i], i));
                if (nums_map.count(residual)) // if residual already exists in map
                {
                    // nums_map[residual] is not i, as nums_map[residual] is the idx of the 'past' loop, while i is the idx of the 'current' loop.
                    return {nums_map[residual], i};
                }
                else // if residual Not exist in map
                {
                    nums_map.insert({nums[i], i});
                }
                
            }
            return {0, 0};
        }
};

int main(void)
{
    Solution2 func;
    vector<int> nums = {5, 7, 5};
    int target = 10;
    vector<int> ans = func.twoSum(nums, target);
    cout << nums[ans[0]] << '+' << nums[ans[1]] << '=' << target << endl;

    return 0;
}