// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the 
// relative order of positive and negative elements, you must return an array of alternately positive and negative values.

#include<iostream>
#include<vector>
using namespace std;

void rearrange1(vector<int> &nums) {
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<nums.size(); i++) {
        if(nums[i] > 0) 
        pos.push_back(nums[i]);

        else
        neg.push_back(nums[i]);
    }

    for(int i=0; i<nums.size(); i+=2) {
        nums[i] = pos[i/2];
        nums[i+1] = neg[i/2];
    }
}

void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) 
    cout << nums[i] << " ";
}

int main() {
    vector<int> arr = {1,-2,3,4,-5,-6};
    rearrange1(arr);
    printArr(arr);
}