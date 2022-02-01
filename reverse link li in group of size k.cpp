class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if (head == nullptr) {
            return head;
        }
        int count = 0;
        node* prev = nullptr;
        node* current = head;
        node* next = nullptr;
        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        node* next_head = reverse(next, k);
        head->next = next_head;
        return prev;
        
    }
};

