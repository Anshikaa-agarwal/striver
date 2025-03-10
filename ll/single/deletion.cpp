#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;

    public:
    node(int value, node* temp) {
        this->data = value;
        this->next = temp;
    }

    node(int value) {
        this->data = value;
        this->next = nullptr; 
    }
};

void insertHead(node* &head, int value) {
    node* newNode = new node(value);
    newNode -> next = head;
    head = newNode;
}

void deleteEnd(node* &head) {
    if(head==nullptr) {
        cout << "Empty linked list.";
        return;
    }

    if(head->next == nullptr) {
        delete head;
        head=nullptr;
        return;
    }
    node* temp = head;

    while(temp->next->next!=nullptr) {
        temp=temp->next;
    }

    delete temp->next;
    temp->next=nullptr;
}

void deleteStart(node* &head) {
    if(head == nullptr) {
        cout << "empty linked list.";
        return;
    }

    node* temp = head;
    head = temp->next;

    delete temp;
}

void deleteIndex(node* &head, int index) {
    node* temp = head;

    for (int i = 0; i < index - 1; i++) {
        if (temp->next == nullptr) {  // Index out of bounds
            cout << "Index out of bounds." << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp->next == nullptr) {  // Trying to delete beyond list length
        cout << "Index out of bounds." << endl;
        return;
    }

    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void printLL(node* &head) {
    node* temp = head;
    if(head == nullptr) return;

    while(temp->next != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    node* head = new node(5);
    insertHead(head, 4);
    insertHead(head, 3);
    insertHead(head, 2);
    insertHead(head, 1);

    deleteIndex(head, 2);
    printLL(head);
}