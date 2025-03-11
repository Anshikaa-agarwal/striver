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

}