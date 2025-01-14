// Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

/*
Example 1:  vec[]={4,7,9,10}, k = 1, result = 1
            explanation:  The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.

Example 2:  vec[]={4,7,9,10}, k = 4, result = 5
            explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 4, the fourth missing element is 5.
*/

#include<iostream>
#include<vector>
using namespace std;
int missingNum(vector<int> &arr, int k) {
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]<=k) k++;
        if(arr[i]>k) return k;
    }
    return -1;
}
int main() {
    vector<int> arr = {4,7,9,10};
    int k=4;
    cout << missingNum(arr, k);
}