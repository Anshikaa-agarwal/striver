// arr[] = {1,2,3,4,5,6,7,8,9}, k=2
// output arr[] = {3,4,5,6,7,8,9,1,2}
#include<iostream>
#include<vector>
using namespace std;
void swap(int &x, int& y) {
    x=x+y;
    y=x-y;
    x=x-y;
}
void reverseArray(vector<int> &arr, int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rotateLeftK(vector<int> &arr, int k) {
    int n = arr.size();
    k=k%n;
    reverseArray(arr, 0, k-1);
    reverseArray(arr, k, n-1);
    reverseArray(arr, 0, n-1);
}
void method2(vector<int> &arr, int k) {
    vector<int> temp;
    int n = arr.size();
    int x = 0;
    for(int i=0; i<k; i++) {
        temp.push_back(arr[i]);
    }
    for(int i=0; i<n-k; i++) {
        arr[i] = arr[i+k];
    }
    for(int i=n-k; i<n; i++) {
        arr[i] = temp[x++];
    }
}
void printArray(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    vector<int> arr2 = {1,2,3,4,5,6,7,8,9};
    cout << "Original Array: ";
    printArray(arr);

    rotateLeftK(arr, 2);
    cout << endl << "Rotated array: ";
    printArray(arr);

    method2(arr2, 2);
    cout << endl << "Rotated array: ";
    printArray(arr2);

    return 0;
}