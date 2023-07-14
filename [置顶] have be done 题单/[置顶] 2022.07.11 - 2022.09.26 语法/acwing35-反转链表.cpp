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
    ListNode* reverseList(ListNode* head) {
    	if (!head || !head->next) return head;
        ListNode* p = head, *q = p->next;
        
        while (q)
        {
        	ListNode* o = q->next;
        	q->next = p;
        	p = q;
        	q = o;
		}
		head->next = NULL;
        return p;
        
    }
};
