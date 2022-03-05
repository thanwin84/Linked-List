class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr){
            return nullptr;
        }
        Node * current = head;
        Node * front = head;
        while (current){
            Node * front = current->next;
            Node * copy = new Node(current->val);
            // link the copy the node right next to original node
            current->next = copy;
            copy->next = front;
            // set the current node
            current = front;
        }
        current = head;
        Node * copy = head->next;
        while (current){
            Node * front = copy->next;
            // check if we have random pointer in original node
            // if exits, also change in the copy node
            if (current->random){
                copy->random = current->random->next;
            }
            current = front;
            if (current){
                copy = front->next;
            } 
        }
        current = head;
        Node * dummy = new Node(0);
        copy = dummy;
        while (current){
            Node * front = current->next->next;
            copy->next = current->next;
            // move the copy node 
            copy = copy->next;
            current->next = front;
            current = front;
        }
        return dummy->next;
    }
};
