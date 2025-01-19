# include <map>
# include <algorithm>
# include <vector>
# include <iostream>
# include <unordered_map>
# include <stack>
using namespace std;

class Solution1
{
public:
    bool isValid(string s)
    {
        if (s.size()%2!=0) // not even, not closed properly
        {
            cout << "int(s[0]=) " << s[0] << endl;
            cout << "s.size()%2= " << s.size()%2 << endl;
            return false;
        }
        else
        {
            //ASCII
            //(: 40; ):41
            //[: 91; ]:93
            //{: 123; }:125
            std::stack<int> open_brackets;
            for (int i=0; i<s.size(); i++)
            {
                if (int(s[i])==40 || int(s[i])==91 || int(s[i])==123) // current bracket is open bracket
                {
                    open_brackets.push(int(s[i]));
                }
                else if (int(s[i])==41 || int(s[i])==93 || int(s[i])==125) // current bracket is close bracket
                {
                    if (open_brackets.empty()) //there should be at least 1 open bracket to match
                    {
                        cout << "empty stack" << endl;
                        return false;
                    }
                    
                    switch (int(s[i]))
                    {
                        case 41:
                            if (open_brackets.top()!=40) // the latest open bracket is not '('
                            {
                                return false;
                            }
                            else // match successfully => pop out the latest open bracket
                            {
                                open_brackets.pop();
                                break;
                            }
                        case 93:
                            if (open_brackets.top()!=91) // the latest open bracket is not '['
                            {
                                return false;
                            }
                            else // match successfully => pop out the latest open bracket
                            {
                                open_brackets.pop();
                                break;
                            }
                        case 125:
                            if (open_brackets.top()!=123) // the latest open bracket is not '{'
                            {
                                return false;
                            }
                            else // match successfully => pop out the latest open bracket
                            {
                                open_brackets.pop();
                                break;
                            }
                    }
                }
                else
                {
                    cout << "something is wrong with input s" << endl;
                    return false;
                }
            }

            
            return open_brackets.empty();
            
        }
    }
};

class Solution2 {
public:
    bool isValid(string s)
    {
        stack<char> open;
        std::unordered_map<char, char> parens = {
            {')', '('},
            {']', '['},
            {'}', '{'},
            // key: close bracket
            // value: open bracket
        };
        
        for (const auto& c : s)
        {
            // if parens.find(c) is not parens.end(), that means there is a key that is c
            // which means we meet close bracket in this case
            // if parens.find(c) is parens.end(), that means there is no key like c
            // so that must be open bracket
            if (parens.find(c) != parens.end()) // meet close bracket => match with open bracket stack
            {
                if (open.empty())
                {
                    return false;
                }

                if (open.top() != parens[c])
                {
                    return false;
                }

                open.pop();

            } else // meet open bracket 
            {
                open.push(c); // stack open bracket
            }
        }
        
        return open.empty();
    }
};

int main(void)
{
    Solution2 func;
    string s = "(()[{}])";
    bool result = func.isValid(s);
    
    if (result)
    {
        std::cout << "Valid" << std::endl;
    }
    else
    {
        std::cout << "Not Valid" << std::endl;
    }
    // std::cout << int('}') << std::endl;
    return 0;
}