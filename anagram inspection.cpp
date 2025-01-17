#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>

using std::string;
using std::map;
using std::pair;



class Solution1 // Sort s&t then check if s == t: Time: O(n^2) or O(nlogn) depending on sorting algorithm
{
    public:
        bool isAnagram(string s, string t) 
        {
            std::sort(s.begin(), s.end());
            std::sort(t.begin(), t.end());

            if (s == t)
            {
                return true;
            }
            else
            {
                return false;
            }
            
            
        }
};

class Solution2 // Build 2 hash maps for s & t, which save the appearance number of alphabets: Time: O(s+t)
{
    public:
        bool isAnagram(string s, string t) 
        {
            if (s.size() != t.size())
            {
                return false;
            }
            else
            {
                map<char, int> count_s;
                map<char, int> count_t;

                for (int i=0; i<s.size(); i++)
                {
                    count_s[s[i]]++;
                    count_t[t[i]]++;
                }

                for (map<char, int>::iterator iter=count_s.begin(); iter!=count_s.end(); iter++) // check if every key in s&t have same value
                {
                    // std::cout << iter->first << ':' << iter->second << std::endl;
                    std::cout << (*iter).first << ':' << (*iter).second  << std::endl;
                    if (count_s[iter->first] != count_t[iter->first])
                    {
                        return false;
                    }
                }

                return true;
            }
            
        }
};

int main(void)
{
    Solution2 func;
    string s = "aabdbaee";
    string t = "aabdbaee";
    bool result = func.isAnagram(s, t);
    if (result)
    {
        std::cout << "Find anagram" << std::endl;
    }
    else
    {
        std::cout << "No anagram" << std::endl;
    }
    
    return 0;
}
