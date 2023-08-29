#include <string>
#include <map>

class Solution
{
public:
    bool isInterleave(const std::string &s1, const std::string &s2, const std::string &s3)
    {
        if (s3.size() != s1.size() + s2.size())
            return false;

        return dfs(s1, s2, s3, 0, 0);
    }

private:
    std::map<std::pair<int, int>, bool> dp;

    bool dfs(std::string s1, std::string s2, std::string s3, int i, int j)
    {
        if (i == s1.size() && j == s2.size())
            return true;

        if (dp.find({i, j}) != dp.end())
            return dp[{i, j}];

        if (i < s1.size() && s1[i] == s3[i + j] && dfs(s1, s2, s3, i + 1, j))
            return true;

        if (j < s2.size() && s2[j] == s3[i + j] && dfs(s1, s2, s3, i, j + 1))
            return true;

        dp[{i, j}] = false;

        return dp[{i, j}];
    }
};