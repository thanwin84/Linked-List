// time: O(n) and space: O(1)
//algorithm: if current node  next value is greater than previous value, then we have to delete the previous value. but in the singly linked list, we can't go back
// so have to reverse the linked list
// initially,  set max_node = head
// if current.next  value is less than max_node, that means we have to delete current.next and link the current node to current.next.next
// otherwise move the current node to next node and set max_node

class Solution
{
    public:
    Node * reverse(Node * head){
        Node * current = head;
        Node * prev = nullptr;
        while (current){
            Node * next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node * new_head = reverse(head);
        Node * max_node = new_head;
        Node * current = new_head;
        while (current && current->next){
          // next node value is less than max_node
            if (current->next->data < max_node->data){
                Node * temp = current->next->next;
                current->next = temp;
            }
          // next node value is greater than max_node value
            else {
                current = current->next;
                max_node = current;
            }
        }
        head = reverse(new_head);
        return head;
    }
    
};
   
