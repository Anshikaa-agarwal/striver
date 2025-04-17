#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    public:
    node(int value, node* next1, node* prev1) {
        this->data=value;
        this->next=next1;
        this->prev=prev1;
    }

    node(int value) {
        this->data=value;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

int main() {
    vector<int> arr = {1,2,3,4,5};
    node* head = new node(arr[0]);
    node* current = head;

    for(int i=1; i<arr.size(); i++) {
        node* temp = new node(arr[i]);
        current->next=temp;
        temp->prev=current;

        current=temp;
    }

    node* ptr = head;
    cout << "Forward: ";
    while(ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << "\nBackward: ";
    ptr = current; // current is now the last node
    while(ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
}
int main() {
    
}