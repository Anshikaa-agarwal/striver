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

void insertEnd(node* &head, int value) {
    node* temp = head;
    node* newNode = new node(value);
    //move to end of linkedlist
    while(temp->next!=nullptr) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void insertIndex(node* &head, int index, int value) {
    node* temp = head;
    node* newNode = new node(value);

    for(int i=0; i<index-1; i++) {
        if(temp==nullptr) {
            cout << "index out of bounds.";
            return;
        }
        temp=temp->next;
    }

    if (temp == nullptr) {
        cout << "Index out of bounds" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void insertBeforeValue(node* &head, int key, int value) {
    node* temp = head;
    if(head==nullptr) {
        cout << "empty linked list.";
        return;
    }

    node* newNode = new node(value);

    while(temp->next->data!=key && temp->next!=nullptr) 
    temp = temp->next;

    if(temp->next==nullptr) {
        cout << "no value found.";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertSorted(node* &head, int value) {
    if(head==nullptr) {
        insertHead(head, value);
        return;
    }

    node* newNode = new node(value);
    node* temp = head;

    while(temp->next->data <= value && temp->next!=nullptr) {
        temp=temp->next;
    }

    if(temp->next==nullptr) {
        insertEnd(head, value);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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
    insertEnd(head, 13);

    insertIndex(head, 3, 6);
    insertBeforeValue(head, 12, 11);
    insertSorted(head, 7);
    printLL(head);

    return 0;
}