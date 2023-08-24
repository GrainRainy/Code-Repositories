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
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) 
	{
		int cntA = 0, cntB = 0; 
		ListNode *p = headA, *q = headB;
		while (p != q)
		{
			if (!p) p = headB;
			else p = p->next;
			if (!q) q = headA;
			else q = q->next;
		}
		return p;
    }
};
