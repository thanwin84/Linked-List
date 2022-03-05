// dutch national flag algorithm
// time: O(n) and space: O(1)
class Solution
{
public:
    void swap(Node* node1, Node* node2) {
        int temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        int mid_value = 1;
        Node * p_node = head;
        Node* current = head;
        while (current) {
            if (current->data < mid_value) {
                swap(p_node, current);
                p_node = p_node->next;
            }
            current = current->next;
        }
        current = p_node;
        while (current) {
            if (current->data == mid_value) {
                swap(p_node, current);
                p_node = p_node->next;
            }
            current = current->next;
        }
        return head;
    }
};
