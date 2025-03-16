#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    public:
    node(int value, node* prev1, node* next1) {
        this->data=value;
        this->prev=prev1;
        this->next=next1;
    }

    node(int value) {
        this->data=value;
        this->prev=nullptr;
        this->next=nullptr;
    }
};

void insertHead(node* &head, int value) {
    node* temp = new node(value);
    temp->next=head;
    head->prev=temp;
    head=temp;
}


node* insertTail(node* &head, int value) {
    node* newNode = new node(value);
    if(head==nullptr) return newNode;

    node* temp = head;
    while(temp->next!=nullptr) {
        temp=temp->next;
    }

    newNode->prev=temp;
    temp->next=newNode;

    return head;
}

void insertIndex(node* &head, int index, int value) {
    node* temp = head;
    for(int i=0; i<index-1; i++) {
        temp=temp->next;
    }
}

void printLL(node* head) {
    if(head==nullptr) return;
    node* temp = head;
    while(temp!=nullptr) {
        cout << temp->data << " ";
        temp=temp->next;
    }
}

int main() {
    node* head = new node(5);
    insertHead(head, 4);
    insertHead(head, 3);
    insertHead(head, 2);
    insertHead(head, 1);

    printLL(head);
    return 0;
}