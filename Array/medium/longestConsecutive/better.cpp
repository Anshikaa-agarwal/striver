/*Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longestSubsequence(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int longest=0, count=1;
    for(int i=0; i<arr.size()-1; i++) {
        if(arr[i]==arr[i+1]-1) count++;
        else {
            longest = max(longest, count);
            count = 1;
        }
    }
    return longest;
} 
int main() {
    vector<int> arr = {1,2,5,3,4,10,11,13,12,9};
    int count = longestSubsequence(arr);
    cout << count;
    return 0;
}