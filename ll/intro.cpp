#include<iostream>
#include<vector>
using namespace std;

// declaration
class node {
    public: 
    int data;
    node* next;

    public:
    node(int data1, node* next1) {
        this->data = data1;
        this->next = next1;
    }

    node(int data1) {
        this->data = data1;
        this->next = nullptr;
    }
};
void insertHead(node* &head, int value) {
    node* temp = new node(value);
    temp->next = head;
    head = temp;
}
void printLL(node* &head) {
    node* temp = head;
    while(temp!=nullptr) {
        cout << temp->data << " ";
        temp = temp ->next;
    }
}
int main() {
    node* head = new node(12);
    insertHead(head, 5);
    insertHead(head, 4);
    insertHead(head, 3);
    printLL(head);

    return 0;
}