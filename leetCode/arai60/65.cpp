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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        if(fast->next==nullptr||fast->next->next==nullptr)return nullptr;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast->next==nullptr || fast->next->next==nullptr)return nullptr;
            if(fast==slow)break;
        }
        slow = head;
        while(slow!=fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};