//author - Vedant Chavda
// 20 Jan 2020
// problem link - https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        n--;
        m--;
        
        ListNode *cur = head;
        ListNode *prev = nullptr;
        
        int c = 0;
        
        while (c < m)
        {
            prev = cur;
            cur = cur -> next;
            c++;
        }
        
        // cur is at position m
        
        ListNode *posm = cur;
        ListNode *beforem = prev;
        if (cur -> next == nullptr)
            return head;
        
        ListNode *next = cur -> next;
        
        
        while (c < n)
        {
            c++;
            cur -> next = prev;
            prev = cur;
            cur = next;
            next = next -> next;
        }
        
        // cur is at position n
        ListNode *aftern = cur -> next;
        cur -> next = prev;
        
        if (beforem == nullptr)
        {
            if (aftern== nullptr)
            {
                head = cur;
                posm -> next = nullptr;
                return head;
            }
            else
            {
                posm -> next = aftern;
                head = cur;
                return head;
            }
        }
        else
        {
            if (aftern == nullptr)
            {
                beforem -> next = cur;
                posm -> next = nullptr;
                return head;
            }
            else
            {
                beforem -> next = cur;
                posm -> next = aftern;
                return head;
            }
        }
    }
};