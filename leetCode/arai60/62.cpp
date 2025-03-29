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
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        if (fast->next == nullptr || fast->next->next == nullptr)
            return nullptr;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast->next == nullptr || fast->next->next == nullptr)
                return nullptr;
            if (slow == fast)
                break;
        }

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;

        }
        return fast;
    }
};