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
    vector<int> printListReversingly(ListNode* head) {
    	vector<int> a;
        for (auto p = head; p != NULL; p = p->next)
        	a.push_back(p->val);
        reverse(a.begin(), a.end());
        	return a;
    }
};
