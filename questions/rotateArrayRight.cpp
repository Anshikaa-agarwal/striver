// arr[] = {1,2,3,4,5}
// rotated arr[] = {5,1,2,3,4}
#include<iostream>
#include<vector>
using namespace std;
void rotateRight(vector<int> &arr) {
    int n = arr.size();
    int temp = arr[n-1];
    for(int i=n-1; i>=1; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}
void printArray(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}
int main() {
    vector<int> arr = {1,2,3,4,5};
    cout << "Original array: ";
    printArray(arr);

    rotateRight(arr);
    cout << endl << "Rotated array: ";
    printArray(arr);

    return 0;
}