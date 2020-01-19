//author - Vedant Chavda
// 19 Jan 2020
// problem link - https://leetcode.com/problems/merge-two-sorted-lists/
// warning - really messy!

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *prev1 = nullptr;
        ListNode *prev2 = nullptr;
        ListNode *next1 = cur1 -> next;
        ListNode *next2 = cur2 -> next;
        
        
        
        while (next1 != nullptr && next2 != nullptr)
        {
            if (cur1 -> val < cur2 -> val)
            {
                prev1 = cur1;
                cur1 = next1;
                next1 = next1 -> next;
            }
            else
            {
                if (prev1 == nullptr)
                {
                    l1 = cur2;
                    prev1 = cur2;
                }
                else
                prev1 -> next = cur2;
                
                cur2 -> next = cur1;
                prev1 = cur2;
                prev2 = cur2;
                cur2 = next2;
                next2 = next2 -> next;
            }
        }
        
        if (next1 == nullptr)
        {
            if (cur1 -> val > cur2 -> val)
            {
                if (cur2 -> next == nullptr)
                {
                    if (prev1 == nullptr)
                {
                    l1 = cur2;
                    prev1 = cur2;
                }
                    prev1 -> next = cur2;
                    cur2 -> next = cur1;
                    cur1 -> next = nullptr;
                }
                else
                {
                    if (prev1 == nullptr)
                    {
                        l1 = cur2;
                        prev1 = cur2;
                    }
                    else
                        prev1 -> next = cur2;
                    while (cur2 != nullptr && cur2 -> val < cur1 -> val)
                    {
                        prev2 = cur2;
                        cur2 = cur2 -> next;
                    }
                    prev1 = prev2;
                    
                    if (cur2 == nullptr)
                    {
                        if (prev1 == nullptr)
                {
                    l1 = cur2;
                    prev1 = cur2;
                }
                        //prev1 -> next = prev2;
                        prev1 -> next = cur1;
                    }
                    else
                    {
                        prev1 -> next = cur1;
                        cur1 -> next = cur2;
                    }
                    // prev1 -> next = cur2;
                    // cur2 -> next = cur1;
                    // cur1 -> next = next2;
                }
            }
            else
            {
                cur1 -> next = cur2;
            }
        }
        else
        {
            if (cur1 -> val < cur2 -> val)
            {
                while (cur1 != nullptr && cur1 -> val < cur2 -> val)
                {
                    prev1 = cur1;
                    cur1 = cur1 -> next;
                    //next1 = next1 -> next;
                }
                
                if (cur1 == nullptr)
                {
                    if (prev1 == nullptr)
                {
                    l1 = cur2;
                    prev1 = cur2;
                }
                    prev1 -> next = cur2;
                }
                else
                {
                    if (prev1 == nullptr)
                {
                    l1 = cur2;
                    prev1 = cur2;
                }
                    prev1 -> next = cur2;
                    cur2 -> next = cur1;
                }
            }
            else
            {
                if (prev1 == nullptr)
                {
                    l1 = cur2;
                    prev1 = cur2;
                }
                prev1 -> next = cur2;
                cur2 -> next = cur1;
            }
        }
        return l1;
    }
    
    
};