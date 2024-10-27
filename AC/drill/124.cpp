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
        ListNode* ptr = dummy;
        while(ptr->next!=nullptr && ptr->next->next!=nullptr){
            if(ptr->next->val==ptr->next->next->val){
                ListNode* copy = ptr->next;
                while(copy->val==copy->next->val&&copy->next->next!=nullptr){
                    copy->next = copy->next->next;
                }
                ptr->next = copy->next;
            }else{
                ptr=ptr->next;
            }
        }
        return dummy->next;
    }
};