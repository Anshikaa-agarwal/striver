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


int main() {
    node* head = new node(5);

    printLL(head);
    return 0;
}