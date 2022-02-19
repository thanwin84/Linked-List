void deleteNode(struct Node** head, int key)
{

    // Your code goes here
    Node* current = *head;
    // if key is equal to head node
    if (current->data == key) {
        Node* after_deleted_node = current->next;
      // move current pointer by one step each time until we reach to the the last element
        while (current->next != *head) {
            current = current->next;
        }
      // now link the last element to new head
        current->next = after_deleted_node;
      // changing the prev head to the new head
        *head = after_deleted_node;
    }
    Node* prev = nullptr;
  // move current pointer by one step until we reach at the end
    while (current->next != *head) {
        if (current->data == key) {
            // delete the node
            prev->next = current->next;
            break;
        }
        prev = current;
        current = current->next;
    }
  // it will handle the last element of circular linked list
    if (current->data == key) {
      // delete last element
        prev->next = current->next;
    }

}

/* Function to reverse the linked list */
void reverse(struct Node** head_ref)
{

    // Your code goes here
    Node* current = *head_ref;
    Node* last_node = current;
    Node* prev = nullptr;
    while (current->next != *head_ref) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current->next = prev;
    prev = current;
    last_node->next = prev;
  // changing the head to new head
    *head_ref = prev;
   
}
