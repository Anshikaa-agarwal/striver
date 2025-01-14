/*Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool linearSearch(vector<int> arr, int target) {
    for(int i=0; i<arr.size(); i++) if (arr[i] == target) return true;
    return false;
}
int longestSubsequence(vector<int> arr) {
    int count = 1, longest=0;
    for(int i=0; i<arr.size(); i++) {
        int element = arr[i];
        if(linearSearch(arr, ++element)) count++;
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