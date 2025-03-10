#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value, node* nextNode) {
        this->data=value;
        this->next=nextNode;
    }

    node(int value) {
        this->data = value;
        this->next=nullptr;
    }
};

void insertLast(node* &head, int value) {
    node* newNode = new node(value);

    if(head==nullptr) {
        head=newNode;
        return;
    }
    node* temp = head;

    while(temp->next!=nullptr) {
        temp=temp->next;
    }
    temp->next=newNode;
}

int lengthLL(node* &head) {
    if(head==nullptr) return 0;
    if(head->next==nullptr) return 1;

    node* temp = head;
    int count=0;
    while(temp!=nullptr) {
        temp=temp->next;
        count++;
    }
    return count;
}

void printLL(node* &head) {
    if(head==nullptr) return;

    node* temp = head;
    while(temp!=nullptr) {
        cout << temp->data << " ";
        temp=temp->next;
    }
}

int main() {
    node* head = new node(1);
    insertLast(head, 2);
    insertLast(head, 3);
    insertLast(head, 4);
    insertLast(head, 5);

    printLL(head);

    cout << endl << "Size of linked list: " << lengthLL(head);
    return 0;
}