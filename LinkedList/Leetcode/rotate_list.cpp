// author - Vedant Chavda
// 19 Jan 2020
// problem link - https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == nullptr || k==0)
            return head;
        
        int length = 0;
        
        ListNode *cur = head;
        while (cur != nullptr)
        {
            length++;
            cur = cur -> next;
        }
        
        k = k%length;
        
        if (k==0)
            return head;
        
        cur = head;
        
        int c = 0;
        while (c < length - k - 1)
        {
            c++;
            cur = cur -> next;
        }
        
        if (cur -> next == nullptr)
        {
            cur -> next = head;
            head -> next = nullptr;
            return cur;
        }
        
        ListNode *newstart = cur -> next;
        ListNode *newhead = newstart;
        cur -> next = nullptr;
        
        while (newstart -> next != nullptr)
            newstart = newstart -> next;
        
        newstart -> next = head;
        
        return newhead;
        
        
    }
};