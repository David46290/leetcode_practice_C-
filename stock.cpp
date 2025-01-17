# include <map>
# include <algorithm>
# include <vector>
# include <iostream>
# include <unordered_map>

using namespace std;

class Solution1 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int past_min = prices[0];
        int new_max = prices[0];
        int best_profit_sor_far = new_max - past_min;
        for (int i=1; i<prices.size(); i++)
        { 
            int current_profit = prices[i] - past_min;
            if (current_profit > best_profit_sor_far) // hit new & elder local maximum
            {
                new_max = prices[i];
                best_profit_sor_far = current_profit;
            }
            else // either hit new local minimum or same price
            {
                if (prices[i] < past_min) // check wether the new minimum is worth buying
                {
                    past_min = prices[i];
                }
                
            }
        }
        return best_profit_sor_far;
    }
};

class Solution2 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int past_idx = 0; // idx of the past day (buying day)
        int new_idx = 1; // idx of the new day (selling day)
        int max_profit = 0;
        while (new_idx < prices.size())
        {
            if (prices[new_idx] < prices[past_idx]) // loss money, hit new low, need buying
            {
                past_idx = new_idx;
            }
            else // either 0 profit or make money
            {
                max_profit = std::max(max_profit, prices[new_idx]-prices[past_idx]);
            }
            new_idx++;
        }
        return max_profit;
    }
};

int main(void)
{
    Solution2 func;
    vector<int> prices = {7, 3, 5, 1, 2};
    int result = func.maxProfit(prices);
    std::cout << "Maximum Profit:" << result << std::endl;
    return 0;
}