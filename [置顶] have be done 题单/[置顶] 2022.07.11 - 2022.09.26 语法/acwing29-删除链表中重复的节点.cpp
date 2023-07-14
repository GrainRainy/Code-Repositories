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
    ListNode* deleteDuplication(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy;
        while (p->next)
        {
        	ListNode *q = p->next;
        	while (q->next && q->next->val == p->next->val) q = q->next;
        	if (q != p->next) p->next = q->next;
        	else p = q;
		}
		return dummy->next;
    }
};
