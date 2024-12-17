/*Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int longestSubsequence(vector<int> arr) {
    //insert elements into set, O(1)
    unordered_set<int> nums(arr.begin(), arr.end());
    int longest = 0;
    
    for(int i=0; i<nums.size(); i++) {
        //check if current element is 1st element of sequence
        if(nums.find(arr[i]-1)==nums.end()) { //checking if previous element is present or not
            //if not
            int current = arr[i];
            int count = 1;

            while(nums.find(++current)!=nums.end()) count++;

            longest = max(longest, count);
        }
    }
    return longest;
}
int main() {
    vector<int> arr = {1,2,5,3,4,10,11,13,12,9,0,-1,-2};
    int count = longestSubsequence(arr);
    cout << count;
    return 0;
}