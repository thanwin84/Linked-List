#include <iostream>
#include<string>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};
void insert_at_tail(Node* &head, int value){
    Node* new_node = new Node(value);
    if (head == nullptr){
        head = new_node;
        return;
    }
    Node*temp = head;
    while (temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}
void insert_at_head(Node* &head, int value){
    Node * new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}
int get_value_at_index(Node* &head, int key){
    Node* current = head;
    int count = 0;
    key = key-1;
    while (count < key){
        current = current->next;
        count ++;
    }
    return current->data;
}
void reverse(Node* &head){
    Node * prev = nullptr;
    Node * current = head;
    Node*Next = nullptr;
    while (current != nullptr){
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }
    head = prev;
}
void display(Node* head){
    Node*current = head;
    while (current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node*head = nullptr;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 10);
    insert_at_head(head, 12);
    display(head);
    reverse(head);
    display(head);
    return 0;
}
