#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &arr) {
    for(int i=1; i<arr.size(); i++) {
        int key = arr[i];
        int j=i-1;

        while(j>=0 && key<arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}

int main() {
    vector<int> arr = {14,19,40,32,89,-3};
    insertionSort(arr);
    printArr(arr);
    return 0;
}