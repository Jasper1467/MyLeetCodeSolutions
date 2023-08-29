#include <string>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Check for overflow, as well as these aren't palindromes
        if (x == INT_MAX || x == INT_MIN)
            return false;

        std::string str = std::to_string(x);

        int nMedian = (x + 1) / 2;
        int nMedianIndex = str.find(str);

        std::string szFirstPart = str.substr(0, nMedianIndex); // from 0 to nMedian
        std::string szSecondPart = str.substr(nMedianIndex);   // from nMedian to end

        return szFirstPart == std::string(szFirstPart.rbegin(), szFirstPart.rend()) && szSecondPart == std::string(szSecondPart.rbegin(), szSecondPart.rend());
    }
};
