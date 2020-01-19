// author = Vedant Chavda
// 19 Jan 2020
// problem link - https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int length = 0;
        if (k==1 || head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *cur = head;
        while (cur != nullptr)
        {
            length++;
            cur = cur -> next;
        }
        
        int iterations = length/k;
        
        cur = head;
        ListNode *prev = nullptr;
        ListNode *next = cur -> next;
        ListNode *start1;
        for (int i=0;i<iterations;i++)
        {
            // reverse from cur to cur + k;
            
            int c = 0;
            ListNode *start = cur;
            start1 = cur;
            while (c < k)
            {
                cur -> next = prev;
                prev = cur;
                cur = next;
                if (next != nullptr)
                next = next -> next;
                c++;
            }
            if (i==0)
                head = prev;
            ListNode *temp = cur;
            int cal = 1;
            while (cal < k && temp != nullptr)
            {
                temp = temp -> next;
                cal ++;
            }
            start -> next = temp;
        }
        start1 -> next = cur;
        
        return head;
    }
};