// time: O(n) and space: O(1)
Node * reverse(Node *head){
    Node * current = head;
    Node *prev = nullptr;
    while (current){
        Node * next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node * current = reverse(head);
       int count = 0;
       Node *prev = nullptr;
       while (count < n && current){
           prev = current;
           current = current->next;
           count++;
       }
       if (count == n){
           return prev->data;
       }
       return -1;
       
}
