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
        while(carry!=0 || l1!=nullptr || l2!=nullptr){
            const int v1 = l1!=nullptr ? l1->val:0;
            const int v2 = l2!=nullptr ? l2->val:0;
            const int sum = v1+v2+carry;
            const int digit = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;
            l1 = l1!=nullptr ? l1->next: nullptr;
            l2 = l2!=nullptr ? l2->next: nullptr;
        }
        return ans->next;
    }
};