/*
Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. 
Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. 
If there are multiple peak numbers, return the index of any peak number.

Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, 
the next element should be considered as negative infinity.
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> peakElement(vector<int> &arr) {
    vector<int> result;
    int i=0, n=arr.size();
    if(n==1) return {arr[0]};

    if(arr[0]>arr[1]) result.push_back(arr[0]);
    if(arr[n-1]>arr[n-2]) result.push_back(arr[n-1]);
    while(i<n-2) {
        if(arr[i]<arr[i+1] && arr[i+2]<arr[i+1]) {
            result.push_back(arr[i+1]);
        }
        i++;
    }
    return result;
}
void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}
int main() {
    vector<int> arr = {1,2,1,3,5,6,4};
    vector<int> result = peakElement(arr);
    printArr(result);

    return 0;
}