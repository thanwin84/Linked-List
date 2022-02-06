//time: O(max(m, n)) and space: O(1)
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 void print(ListNode* head) {
     ListNode* current = head;
     while (current) {
         cout << current->val << " ";
         current = current->next;
     }
 }
class Solution {
public:
    ListNode* make_carry_zero(ListNode* current, int carry) {
        ListNode* head = current;
        ListNode* prev = nullptr;
        if (carry && current) {
            while (current) {
                current->val += carry;
                if (current->val >= 10) {
                    int temp = current->val - 10;
                    current->val = temp;
                    carry = 1;
                }
                else {
                    carry = 0;
                    break;
                }
                prev = current;
                current = current->next;
            }
        }
        if (carry) {
            ListNode* new_node = new ListNode(carry);
            prev->next = new_node;
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* current = l1;
        ListNode* current2 = l2;
        ListNode* prev = nullptr;
        while (current && current2) {
            int first = current->val;
            int second = current2->val;
            current->val += second + carry;
            current2->val += first + carry;
            if (current->val >= 10) {
                int temp = current->val - 10;
                current->val = temp;
                current2->val = temp;
                carry = 1;
            }
            else carry = 0;
            prev = current;
            current = current->next;
            current2 = current2->next;
        }
        //if we have same length
        if (!current && !current2 && carry == 0) {
            return l1;
        }
        if (carry) {
            if (!current && !current2) {
                prev->next = new ListNode(carry);
                return l1;
            }
            else if (current) {
                make_carry_zero(current, carry);
                return l1;
            }
            else {
                make_carry_zero(current2, carry);
                return l2;
            }
        }
        //if carry is 0, return which linked list is long
        if (carry == 0) {
            if (current) {
                return l1;
            }
            else {
                return l2;
            }
        }
        
    }
};
int main() {
    ListNode* one = new ListNode(9);
    one->next = new ListNode(9);
    one->next->next = new ListNode(2);
   /* one->next->next->next = new ListNode(9);
    one->next->next->next->next = new ListNode(9);*/
    ListNode* two = new ListNode(9);
    two->next = new ListNode(9);
    two->next->next = new ListNode(3);
    Solution obj;
    ListNode * res = obj.addTwoNumbers(two, one);
    print(res);
    return 0;
}
