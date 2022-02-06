//leetcode question
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = head;
        if (head->next) {
            prev = head;
        }
        else {
            return head;
        }
        ListNode* current = head->next;
        while (current) {
            ListNode* next = nullptr;
            if (prev->val == current->val) {
                if (current->next) {
                    next = current->next;
                    prev->next = next;
                }
                else prev->next = nullptr;
            }
            else {
                prev = current;
            }
            current = current->next;
        }
        return head;
    }
    void show(ListNode* head) {
        ListNode* current = head;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
    }
};
