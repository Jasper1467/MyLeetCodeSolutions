#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *pRes = new ListNode(0);
        ListNode *pCur = pRes;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                pCur->next = list1;
                list1 = list1->next;
            }
            else
            {
                pCur->next = list2;
                list2 = list2->next;
            }

            pCur = pCur->next;
        }

        pCur->next = list1 ? list1 : list2;
        return pRes->next;
    }
};
