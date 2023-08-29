#include <string>

class Solution
{
public:
    int getValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
        }
    }

    int romanToInt(std::string s)
    {
        int nRes = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int nCurrentSymbolVal = getValue(s[i]);

            if (i + 1 < s.length())
            {
                int nNextSymbolVal = getValue(s[i + 1]);

                if (nCurrentSymbolVal >= nNextSymbolVal)
                    nRes += nCurrentSymbolVal;
                else
                {
                    nRes += nNextSymbolVal - nCurrentSymbolVal;
                    i++;
                }
            }
            else
                nRes += nCurrentSymbolVal;
        }

        return nRes;
    }
};