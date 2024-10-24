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
        while(dummy->next!=NULL&&dummy->next->next!=NULL){
            if(dummy->next->val==dummy->next->next->val){
                ListNode* copy = dummy;
                while(copy->next!=NULL && copy->next->next!=NULL && copy->val == copy->next->next->val){
                    copy->next = copy->next->next;
                }
                dummy -> next = copy -> next;
            }else{
                dummy=dummy->next;
            }
        }

        return dummy -> next;
    }
};