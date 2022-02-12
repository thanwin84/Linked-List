class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> arr;
        ListNode * current = head;
        int count = 0;
        while (current){
            arr.push_back(current);
            current = current->next;
            count++;
        }
        if (count % 2 == 0){
            return arr[count / 2];
        }
        else {
            return arr[count / 2];
        }
        
    }
};
//time and space: O(n)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow_ptr = head;
        ListNode * fast_ptr = head;
        while (fast_ptr && fast_ptr->next){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return slow_ptr;
    }
};
//time: O(n) and space: O(1) ....we only have to traverse n/2 times
