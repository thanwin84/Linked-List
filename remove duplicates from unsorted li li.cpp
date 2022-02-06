//time: O(n) and space: O(n)
class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node* head)
    {
        // your code goes here
        unordered_map<int, int> table;
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        Node* current = head;
        while (current && current->next) {
            if (table.count(current->data)) {
                table[current->data] += 1;
            }
            else {
                prev->next = current;
                prev = current;
                table[current->data] = 1;
            }
            current = current->next;
        }
        if (table.count(current->data)) {
            prev->next = nullptr;
        }
        else {
            prev->next = current;
        }
        return dummy->next;
    }
};
