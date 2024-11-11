/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
#include<iostream>
#include<vector>
using namespace std;
int majority(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        int count = 0;
        for(int j=0; j<arr.size(); j++) {
            if(arr[j]==arr[i]) count ++;
        }
        if(count>arr.size()/2) return arr[i]; 
    }
    return -1;
}
int main() {
    vector<int> arr = {1,1,1,1,2,3,4,4,4,4,4,4,4};
    cout << "Majority element is " << majority(arr);
    return 0;
}