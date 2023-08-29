#include <string>
#include <vector>

class Solution
{
public:
    int myAtoi(std::string s)
    {
        bool bIsPositive = true;
        int nResult = 0;
        size_t i = 0;

        // Skip leading whitespace
        while (i < s.length() && std::isspace(s[i]))
            i++;

        // Check for sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
        {
            bIsPositive = (s[i] == '+');
            i++;
        }

        // Process digits
        while (i < s.length() && std::isdigit(s[i]))
        {
            int nDigit = s[i] - '0';
            if (nResult > INT_MAX / 10 || (nResult == INT_MAX / 10 && nDigit > INT_MAX % 10))
                return bIsPositive ? INT_MAX : INT_MIN;

            nResult = nResult * 10 + nDigit;
            i++;
        }

        return bIsPositive ? nResult : -nResult;
    }
};