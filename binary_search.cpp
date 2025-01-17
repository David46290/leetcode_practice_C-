# include <map>
# include <algorithm>
# include <vector>
# include <iostream>
# include <unordered_map>

using namespace std;

class Solution1 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int upper_idx = nums.size();
        int middle_idx = nums.size() / 2;
        int lower_idx = 0;
        for (int i=1; i<nums.size(); i*=2)
        {
            if (nums[middle_idx] > target)
            {
                upper_idx = middle_idx;
                middle_idx = (lower_idx + middle_idx) / 2;
                int test = 0;
            }
            else if (nums[middle_idx] < target)
            {
                lower_idx = middle_idx;
                middle_idx = (upper_idx + middle_idx) / 2;
            }
            else
            {
                return middle_idx;
            }
        }

        if (nums[middle_idx] == target)
        {
            return middle_idx;
        }
        else
        {
            return -1;
        }
        
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + ((r - l) / 2);
            if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};

int main(void)
{
    Solution1 func;
    vector<int> nums = {-1, 0, 5};
    int target = 5;
    int result = func.search(nums, target);
    std::cout << "found idx:" << result << std::endl;
    return 0;
}