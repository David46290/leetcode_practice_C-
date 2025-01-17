# include <map>
# include <algorithm>
# include <vector>
# include <iostream>
# include <unordered_set>
using namespace std;


class Solution1 // Brute Force: O(n^2)
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target)
        {
            int l_idx = 0;
            int r_idx = numbers.size() - 1;
            int left = numbers[l_idx];
            int right = numbers[r_idx];
            // r_idx decreases to l_idx first, then l_idx++, after that r_idx starts from numbers.size()-1 again, loop
            while (l_idx < numbers.size()-1) // outer loop: control l_idx++
            {
                left = numbers[l_idx];
                r_idx = numbers.size() - 1;
                while (l_idx < r_idx) // inner loop: control r_idx++
                {
                    right = numbers[r_idx];
                    if (left + right == target)
                    {
                        return {l_idx, r_idx};
                    }
                    r_idx--;
                }
                l_idx++;
            }
            return {0, 0};
        }
};

class Solution2 // Use Hashmap to check wether residual already exist in current map O(n) in both time & space
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target)
        {
            map<int, int> numbers_map; // start w/ empty map
            int residual = 0;
            for (int i=0; i<numbers.size(); i++)
            {
                residual = target - numbers[i];
                //numbers_map.insert(std::pair<int,int>(numbers[i], i));
                if (numbers_map.count(residual)) // if residual already exists in map
                {
                    // nums_map[residual] is not i, as numbers_map[residual] is the idx of the 'past' loop, while i is the idx of the 'current' loop.
                    return {numbers_map[residual], i};
                }
                else // if residual Not exist in map
                {
                    numbers_map.insert({numbers[i], i});
                }
                
            }
            return {0, 0};
        }
};

int main(void)
{
    Solution1 func;
    vector<int> numbers = {2, 3, 4};
    int target = 6;
    vector<int> ans = func.twoSum(numbers, target);
    
    cout << "found index:" << ans[0] << " & " << ans[1] << endl;

    return 0;
}