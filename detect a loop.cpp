class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode*slow_ptr = head;
        ListNode*fast_ptr = head;
        while (fast_ptr->next && fast_ptr->next->next){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if (slow_ptr == fast_ptr){
                return true;
            }
        }
        return false;
        
    }
};
