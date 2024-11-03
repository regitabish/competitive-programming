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
        ListNode* dummy = new ListNode(0,head);
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* copy = dummy;
        while(copy->next!=nullptr&&copy->next->next!=nullptr){
            if(copy->next->val==copy->next->next->val){
                ListNode* search = copy->next;
                while(search->next!=nullptr&&search->val==search->next->val){
                    search = search->next;
                }
                copy -> next = search->next;
            }else{
                copy = copy->next;
            }
        }
        return dummy->next;
    }
};