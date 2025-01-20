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
            // check whether the middle element is target
            // if it's bigger than the target => we need to go backward (left side)
            //      left_idx not changed, but new right_idx becomes the middle_idx
            // if it's smaller than the target => we need to go forward (right side)
            //      right_idx not changed, but new left_idx becomes the middle_idx
            // if no -/+ 1 for right/left idx
            // the loop will stuck at where middle_idx = left idx
            // and the left_idx will always be smaller than right_idx
            if (nums[m] > target)
            {
                r = m - 1; // -1 because the current middle_idx is out of search range
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                return m; // +1 because the current middle_idx is out of search range
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