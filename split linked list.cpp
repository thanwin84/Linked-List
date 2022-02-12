void splitList(Node* head, Node** head1_ref, Node** head2_ref)
 {
     // your code goes here
     Node* slow_ptr = head;
     Node* fast_ptr = head;
     while (fast_ptr->next != head && fast_ptr->next->next != head) {
         slow_ptr = slow_ptr->next;
         fast_ptr = fast_ptr->next->next;
     }
     *head1_ref = head;
     *head2_ref = slow_ptr->next;
     slow_ptr->next = head;
     Node* current = *head2_ref;
     while (current->next != head){
         current = current->next;
     }
     current->next = *head2_ref;
 }
