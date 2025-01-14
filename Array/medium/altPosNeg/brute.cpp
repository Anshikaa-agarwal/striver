/*Problem Statement:
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.
Note: Start the array with positive elements.*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> rearrange(vector<int> arr) {
    vector<int> pos, neg;
    int k = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    for(int i=0; i<arr.size()/2; i++) {
        arr[k++] = pos[i];
        arr[k++] = neg[i]; 
    }
    return arr;
}
int main() {
    vector<int> arr = {1,2,3,-3,-5,-9};
    arr = rearrange(arr);
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}