// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int length(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int curLen = 0, lastSmallest = INT32_MIN, longest = 1;

    curLen=1;
    lastSmallest = nums[0];

    for(int i=1; i<nums.size(); i++) {

        if(nums[i] == nums[i-1])
        continue;

        if(lastSmallest == nums[i] - 1) {
            lastSmallest = nums[i];
            curLen++;
        }
        else{ 
            lastSmallest=nums[i];
            curLen = 1;
        }

        longest = max(longest, curLen);
    }

    return longest;
}
int longestConsecutiveElement(vector<int> &nums) {
    unordered_set<int> s;
    int n = nums.size();
    int longest = 1;

    for(int i=0; i<nums.size(); i++) 
    s.insert(nums[i]);

    for(auto it: s) {
        // isse phle koi element nhi hai, it's the last one
        if(s.find(it - 1) == s.end()) {
            int count = 1;
            int x = it;

            // jab tk x+1 element exist kr rha hai
            while(s.find(x+1) != s.end()) {
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}
int main() {
    vector<int> arr = {1,2,3,4,3,2,1,4,1,3,7,8,9};
    cout << length(arr) << endl;
    cout << longestConsecutiveElement(arr) << endl;
}