// Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element 
// that is greater than all of the elements on its right side in the array.
#include<iostream>
#include<vector>
using namespace std;

vector<int> leaders(vector<int> &nums) {
    int maxx = INT32_MIN;
    vector<int> result;

    result.push_back(nums[nums.size()-1]);
    for(int i=nums.size()-2; i>=0; i--) {
        maxx = max(maxx, nums[i+1]);
        if(nums[i] > maxx) 
        result.push_back(nums[i]);
    }
    return result;
}
void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) 
    cout << nums[i] << " ";
}

int main() {
    vector<int> arr = {4, 7, 1, 0};
    vector<int> result = leaders(arr);
    printArr(result);
}