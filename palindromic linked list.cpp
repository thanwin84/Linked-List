class Solution {
public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(ListNode* head)
    {
        ListNode * slow_ptr = head;
        ListNode * fast_ptr = head;
        // find the middle element
        while (fast_ptr->next && fast_ptr->next->next) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        // We've found the middle element
        ListNode* middle = slow_ptr;
        // current: head of the right half linked list
        ListNode* current = slow_ptr->next;
        ListNode * prev = nullptr;
        //reverse the right half
        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        // link the left half with right half
        middle->next = prev;
        //head of the next half linked list
        slow_ptr = slow_ptr->next;
        while (slow_ptr) {
            if (head->val != slow_ptr->val) {
                return false;
            }
            head = head->next;
            slow_ptr = slow_ptr->next;
        }
        return true;
    }
};
