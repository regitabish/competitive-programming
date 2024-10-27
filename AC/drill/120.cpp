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
        
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            ListNode* tail = ListNode(0);
            int v1 = (l1!=nullptr) ?l1->val:0;
            int v2 = (l2!=nullptr) ?l2->val:0;
            int sum = v1+v2+carry;
            int dig = sum%10;
            carry = sum/10;
            tail->val = dig;
            
            (l1->next!=nullptr)?l1=l1->next:nullptr;
            (l2->next!=nullptr)?l2=l2->next:nullptr;
            ans->next = tail;
            ans = ans->next;
        }
        return ans;
    }
};