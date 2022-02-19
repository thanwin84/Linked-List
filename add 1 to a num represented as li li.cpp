using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print_nodes(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
}
class Solution
{
public:
    Node* reverse(Node* head) {
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    Node* addOne(Node* head)
    {
        Node* reversed_head = reverse(head);
        Node* current = reversed_head;
        int carry = 1;
        Node* prev = nullptr;
        // add +1 to the current pointer
        // move current pointer by one step each time until carry is equal to zero
        while (current) {
            current->data += carry;
            if (current->data >= 10) {
                carry = 1;
                current->data = 0;
            }
            else {
                // if carry is 0, we don't need to move forward
                carry = 0;
                break;
            }
            prev = current;
            current = current->next;
        }
        // If we're still left with carry after treversing the list
        // we have to add new node at the end of linked list
        if (carry) {
            Node* new_node = new Node(1);
            prev->next = new_node;

        }
        Node* new_head = reverse(reversed_head);
        return new_head;
    }
};
int main() {
    Node* one = new Node(9);
    one->next = new Node(9);
    one->next->next = new Node(9);
    /*one->next->next->next = new Node(5);
    one->next->next->next->next = new Node(3);
    one->next->next->next->next->next = new Node(5);
    one->next->next->next->next->next->next = new Node(4);
    one->next->next->next->next->next->next->next = new Node(4);*/

    Solution obj;
    Node* res = obj.addOne(one);
    print_nodes(res);
    
   
    
    
    return 0;
}
