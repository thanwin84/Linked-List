
Node* merge_linked_list(Node* A, Node* B) {
    Node* temp = new Node(0);
    Node* head = temp;
    while (A && B) {
        if (A->data < B->data) {
            temp->bottom = A;
            temp = temp->bottom;
            A = A->bottom;
        }
        else {
            temp->bottom = B;
            temp = temp->bottom;
            B = B->bottom;
        }
    }
    if (A) {
        temp->bottom = A;
    }
    else if (B) {
        temp->bottom = B;
    }
    return head->bottom;
}

Node* flatten(Node* root)
{
    // Your code here
    if (root == nullptr || root->next == nullptr) {
        return root;
    }
    root->next = flatten(root->next);
    Node* new_node = merge_linked_list(root, root->next);
    return new_node;
}
