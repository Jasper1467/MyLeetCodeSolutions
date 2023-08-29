#include <string>
#include <stack>
#include <unordered_map>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> Stack;
        std::unordered_map<char, char> Mappings = {
             { ')', '('},
             {']', '['},
             {'}', '{' }
        };

        for (char c : s)
        {
            if (Mappings.find(c) != Mappings.end())
            {
                if (Stack.empty() || Stack.top() != Mappings[c])
                    return false;

                Stack.pop();
            }
            else
                Stack.push(c);
        }

        return Stack.empty();
    }
};