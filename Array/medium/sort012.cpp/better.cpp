/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
*/

// Count number of 0's, 1's and 2's in array in one go
#include<iostream>
#include<vector>
using namespace std;
void sort012(vector<int>& arr) {
    int c0 = 0, c1 = 0, c2 = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]==0) c0++;
        else if(arr[i]==1) c1++;
        else if(arr[i]==2) c2++;
        else {
            cout << "Invalid input!";
            return;
        }
    }

    int i=0;
    while(i<c0) arr[i++] = 0;
    while(i<c0+c1) arr[i++] = 1;
    while(i<arr.size()) arr[i++] = 2;
}
void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}
int main() {
    vector<int> arr = {0,1,1,2,1,0,2,1};
    sort012(arr);
    printArr(arr);
    return 0;
}