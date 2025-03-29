/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        while(l1!=nullptr||l2!=nullptr||carry!=0){
            int n1 = (l1==nullptr)?0:l1->val;
            int n2 = (l2==nullptr)?0:l2->val;
            int sum = n1 + n2 + carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;
            l1 = l1!=nullptr?l1->next:nullptr;
            l2 = l2!=nullptr?l2->next:nullptr;
        }
        return ans->next;
    }
};