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
int main() {
    node* newNode = new node(12);
    cout << newNode->data;
}