// time: O(n) and space: O(1)
// in the worst case we have to traverse the whole array twice
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
// Optimized approach
// algorithm: take two pointers(first_pointer and second_pointer)
// treverse n nodes with first pointer(we only have to traverse n -1 times to reach at nth position).
// then treverse first pointer and second pointer simulteniously until the first_pointer.next is not null. 
// When second pointer.next becomes null, second pointer will reach at the desired position
// time: O(n) and space: O(1)
// in the worst case we have to traverse the linked list only once
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node * first = head;
       Node * second = head;
       for (int i = 0; i < n - 1; i++){
           first = first->next;
           if (first == nullptr){
               return -1;
           }
       }
       while (first->next){
           first = first->next;
           second = second->next;
       }
       return second->data;
       
}
