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
        if(head == NULL)return NULL;
        ListNode* copy = head;
        while(copy->next!=NULL){
            if(copy->next->val == copy->val){
                copy->next = copy->next->next;
            }else{
                copy = copy->next;
            }
        }
        return head;
    }
};