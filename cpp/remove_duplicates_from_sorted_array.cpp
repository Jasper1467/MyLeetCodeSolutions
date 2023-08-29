#include <vector>
#include <iostream>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int nSize = nums.size();
        if (nSize == 0)
            return 0;

        int j = 0;
        for (int i = 1; i < nSize; i++)
        {
            if (nums[i] != nums[j])
            {
                j++;
                if (i != j)
                {
                    nums[j] = nums[i];
                }
            }
        }

        return j + 1;
    }
};