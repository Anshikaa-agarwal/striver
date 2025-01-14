// arr[] = {1,2,3,4,5}
// rotated arr[] = {2,3,4,5,1}
#include<iostream>
#include<vector>
using namespace std;
void rotateLeft(vector<int>& arr) {
    int temp = arr[0];
    int n = arr.size();
    for(int i=0; i<arr.size()-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}
void printArray(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}
int main() {
    vector<int> arr = {1,2,3,4,5};
    cout << "Original Array: ";
    printArray(arr);

    rotateLeft(arr);
    cout << endl << "Rotated array: ";
    printArray(arr);

    return 0;
}