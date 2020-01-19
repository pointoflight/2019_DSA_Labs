// author : Vedant Chavda
// 19 Jan 2020
// problem link - https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
           
        if (head == nullptr)
            return true;
        
           ListNode *newhead = (struct ListNode *)malloc(sizeof(struct ListNode));
        ListNode *newh = newhead;
        ListNode *cur = head;
        
        while (cur != nullptr)
        {
            newhead -> val = cur -> val;
            if (cur -> next == nullptr)
            {
                newhead -> next = nullptr;
                break;
            }
            else
            {
                ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
                temp -> val = cur -> next -> val;
                newhead -> next = temp;
                cur = cur -> next;
                newhead = newhead -> next;
            }
        }
        
        cur = newh;
        ListNode *prev = nullptr;
        ListNode *next1 = cur -> next;
        
        while (next1 != nullptr)
        {
            cur -> next = prev;
            prev = cur;
            cur = next1;
            next1 = next1 -> next;
        }
        
        cur -> next = prev;
        
        ListNode *start1 = cur;
        ListNode *start2 = head;
        
        while (start1 != nullptr)
        {
            if (start1 -> val != start2 -> val)
                return false;
            start1 = start1 -> next;
            start2 = start2 -> next;
        }
        
        return true;
        

        
    }
};