
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;

//  https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2025-11-01
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {

        unordered_map<int, int> mp;
        for (auto a : nums)
        {
            mp[a] = 1;
        }

        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *prev = dummyNode;
        ListNode *curr = head;

        while (curr != NULL)
        {
            if (mp[curr->val])
            {
                prev->next = curr->next;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummyNode->next;
    }
};