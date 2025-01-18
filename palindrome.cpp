#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

class Solution1
{
public:
    bool isPalindrome(string s)
    {
        string s_modified = "";
        for (int i=0; i<s.size(); i++)
        {
            if (std::isalpha(s[i]))
            {
                s_modified += std::tolower(s[i]);
            }
            else if (std::isdigit(s[i]))
            {
                s_modified += s[i];
            }
        }

        cout << "original: " << s << endl;
        cout << "only alphabet & lowercase: " << s_modified << endl;
        string s_modified_reversed = s_modified;
        reverse(s_modified_reversed.begin(), s_modified_reversed.end());

        if (s_modified_reversed==s_modified)
        {
            return true;
        }
        else{
            return false;
        }
    }
};

class Solution2
{
    public:
        bool isPalindrome(string s)
        {
            int left_idx = 0;
            int right_idx = s.size() - 1;
            // using left&right idx to inspect whether the 2 characters at both sides is the same
            // if one stop at a non-alphanumeric character, skip to the next inner and alphanumeric character
            int iter = 0;
            while (left_idx < right_idx)
            {
                // make sure both sides stop at alphanumeric characters first
                // conditional expression '&& left_idx < right_idx' is used to deal with 'the middle 2 chars are non-alphanumeric' situation, which have chars of a even number
                // the order of two while loop below not matter
                // isAlphaNumeric: {first=bool, second=ASCII char}
                while (!isAlphaNumeric(s[right_idx]).first && left_idx < right_idx) // if the right side stops at a non-alphanumeric character
                {
                    right_idx --;
                }

                while (!isAlphaNumeric(s[left_idx]).first && left_idx < right_idx) // if the left side stops at a non-alphanumeric character
                {
                    left_idx ++;
                }

                // then, check if both side is not the same
                char left_c = isAlphaNumeric(s[left_idx]).second;
                char right_c = isAlphaNumeric(s[right_idx]).second;
                if (isAlphaNumeric(s[left_idx]).second != isAlphaNumeric(s[right_idx]).second)
                {
                    return false;
                }
                else // if they are same, going to next inner characters
                {
                    left_idx ++;
                    right_idx --;
                }
            }
            // if going through all characters without returning false, it must be palindrome
            return true;
        }

        std::pair<bool, char> isAlphaNumeric(char c)
        {
            // ASCII codes of alphanumeric chars are continuous, so it can be used to check whether one char is alphanumeric
            if (int('A') <= int(c) && int('Z') >= int(c)) // if uppercase
            {
                return std::make_pair(true, std::tolower(c));
            }
            else if (int('a') <= int(c) && int('z') >= int(c)) // if lowercase
            {
                return std::make_pair(true, c);
            }
            else if (int('0') <= int(c) && int('9') >= int(c)) // if number
            {
                return std::make_pair(true, c);
            }
            else
            {
                return std::make_pair(false, c);
            }
        }
};

class Solution3
{
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r) {
            while (!isalnum(s[l]) && l < r) {
                l++;
            }
            while (!isalnum(s[r]) && l < r) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main(void)
{
    Solution2 func;
    string s = "a,a";
    bool result = func.isPalindrome(s);
    if (result)
    {
        std::cout << "Palindrome" << std::endl;
    }
    else
    {
        std::cout << "Not Palindrome" << std::endl;
    }
    


    return 0;
}
