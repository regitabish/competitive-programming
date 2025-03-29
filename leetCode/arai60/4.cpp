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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* copy = head;
        if(head==nullptr||head->next==nullptr)return head;

        while(copy->next!=nullptr){
            if(copy->val==copy->next->val){
                copy->next = copy->next->next;
            }else{
                copy = copy -> next;
            }
        }
        return head;
    }
};