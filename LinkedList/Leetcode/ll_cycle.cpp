// author : Vedant Chavda
// 19 Jan 2020
// problem link - https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        
    
        while (head != nullptr)
        {
            if (head->val == 1563857)
                return head;
            else
            {
                head->val = 1563857;
                head = head->next;
            }
        }
        
        return nullptr;
        
    }
};