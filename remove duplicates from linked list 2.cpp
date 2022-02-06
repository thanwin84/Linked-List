//time: O(n) and space: O(1) since qe are not allocating extra space
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* deleteNode = new ListNode(-250);
        ListNode* current = head;
        while (current && current->next) {
            if (current->val == current->next->val || current->val == deleteNode->val) {
                deleteNode = current;
            }
            else {
                //connecting prev to non duplicate element
                prev->next = current;
                prev = current;
                
            }
            current = current->next;
        }
        if (current && current->val != deleteNode->val) {
            prev->next = current;
        }
      //if we dont' get last node
      // we have to cut prev node so that it doesn't point to nullptr
        else prev->next = nullptr;
        return dummy->next;
    }
    void show(ListNode* head) {
        ListNode* current = head;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
    }
};
