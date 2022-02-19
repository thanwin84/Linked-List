class Solution {
public:
    Node* update(Node* start, int p)
    {
        //Add your code here
        Node* current = start;
        Node* head = start;
        Node* prev = nullptr;
        int count = 0;
        while (current) {
            Node* next = current->next;
            count++;
            if (count == p && next) {
                // making the next pointer as head
                head = next;
                head->prev = nullptr;
                current->next = nullptr;
            }
            prev = current;
            current = next;
        }
        prev->next = start;
        start->prev = prev;
        return head;
    }
};
