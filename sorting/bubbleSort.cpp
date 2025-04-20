#include<iostream>
#include<vector>
using namespace std;

void swapp(int &x, int &y) {
    if(&x == &y) return;
    x=x+y;
    y=x-y;
    x=x-y;
}

void bubbleSort(vector<int> &arr) {
    int end = arr.size();
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<end-1; j++) {
            if(arr[j]>arr[j+1]) swapp(arr[j], arr[j+1]);
        }
        end--;
    }
}

void printArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}

int main() {
    vector<int> arr = {14,19,40,32,89,-3};
    bubbleSort(arr);
    printArr(arr);
    return 0;
}