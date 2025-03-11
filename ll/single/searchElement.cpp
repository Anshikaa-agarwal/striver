#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value, node* newNode) {
        this->data = value;
        this->next = newNode;
    }

    node(int value) {
        this->data = value;
        this->next=nullptr;
    }
};

void insertHead(node* &head, int value) {
    node* temp = new node(value);
    temp->next=head;
    head=temp;
}

void printLL(node* &head) {
    if(head==nullptr) return;

    node* temp = head;

    while(temp!=nullptr) {
        cout << temp->data << " ";
        temp=temp->next;
    }
}

bool searchElement(node* &head, int value) {
    if(head==nullptr) return false;

    node* temp = head;

    while(temp->next!=nullptr) {
        if(temp->data==value) return true;
        temp=temp->next;
    }
    return false;
}
int main() {
    node* head = new node(5);
    insertHead(head, 4);
    insertHead(head, 3);
    insertHead(head, 2);
    insertHead(head, 1);

    printLL(head);

    if(searchElement(head, 3)) cout << "element found.";
    else cout << "not found.";

    return 0;
}