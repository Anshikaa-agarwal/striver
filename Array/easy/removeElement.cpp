/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
The remaining elements of nums are not important as well as the size of nums.
Return k.
*/

#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int> &nums, int k) {
    int i=0;

    for(int j=0; j<nums.size(); j++) {
        if(nums[j] != k) {
            nums[i++] = nums[j];
        }
    }

    return i;
}

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout << removeElement(nums, 2) << endl;

    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}