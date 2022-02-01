struct Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};
class LinkedList {
public:
    Node* head = nullptr;
    void insert_at_the_end(int data) {
        if (head == nullptr) {
            Node* new_node = new Node(data);
            head = new_node;
            return;

        }
        Node* new_node = new Node(data);
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    void insert_at_the_head(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;
    }
    int get_element(int ind) {
        Node* current = head;
        int count = 0;
        while (count < ind - 1) {
            current = current->next;
            count++;
        }
        return current->data;

    }
    void iteratvie_reverse() {
        Node* next = nullptr;
        Node* prev = nullptr;
        Node* current = head;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void solve(Node* prev, Node* current) {
        if (current == nullptr) {
            head = prev;
            return;
        }
        Node* next = current->next;
        current->next = prev;
        prev = current;
        solve(prev, next);

    }
    void recursive_reverse() {
        Node* current = head;
        Node* prev = nullptr;
        solve(prev, current);
    }
    void print() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;

    }

};
int main() {
    LinkedList obj;
    obj.insert_at_the_end(10);
    obj.insert_at_the_end(20);
    obj.insert_at_the_end(38);
    obj.insert_at_the_head(5);
    obj.print();
    obj.recursive_reverse();
    obj.print();
    
    
    return 0;
}
