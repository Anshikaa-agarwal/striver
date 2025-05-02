//Approach: base case when n==1, reduce n by 1 in every recursion
#include<iostream>
#include<vector>
using namespace std;

void swapp(int &x, int &y) {
    if(&x == &y) return;
    x=x+y;
    y=x-y;
    x=x-y;
}
void bubbleSort(vector<int> &arr, int n) {
    if(n==1) return;

    for(int i=0; i<n-1; i++) {
        if(arr[i]>arr[i+1]) swapp(arr[i], arr[i+1]);
    }

    bubbleSort(arr, n-1);
}

void printArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}

int main() {
    vector<int> arr = {14,19,40,32,89,-3};
    bubbleSort(arr, arr.size());
    printArr(arr);
    return 0;
}