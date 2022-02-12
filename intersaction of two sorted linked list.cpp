/// time: O(n + m) and space: O(n + m)
//cuase in the worst case we have to traverse each list one by one
Node* findIntersection(Node* head1, Node* head2)
 {
     // Your Code Here
     Node* new_node_head = nullptr;
     Node* current = head1;
     Node* current2 = head2;
     Node* last_node = nullptr;
     while (current && current2) {
         if (current->data < current2->data) {
             current = current->next;
         }
         else if (current->data > current2->data) {
             current2 = current2->next;
         }
         else {
             Node* new_node = new Node(current->data);
             if (new_node_head == nullptr) {
                 new_node_head = new_node;
                 last_node = new_node_head;
             }
             else {
                 last_node->next = new_node;
                 last_node = new_node;
             }
             current = current->next;
             current2 = current2->next;
         }
     }
     return new_node_head;
 }
