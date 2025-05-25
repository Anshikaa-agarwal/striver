// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int longestSubarray1(vector<int> &nums, int el) {
    // o(n^3)
    int maxx = 0;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i; j<nums.size(); j++) {
            int sum=0;
            for(int k=i; k<=j; k++) {
                sum+=nums[k];
            }
            if(sum==el) {
                maxx = max(maxx, j-i+1);
            }
        }
    }

    return maxx;
}

int longestSubarray2(vector<int> nums, int el) {
    // o(n^2)
    int sum = 0, maxx = 0;

    for(int i=0; i<nums.size(); i++) {
        sum=0;
        for(int j=i; j<nums.size(); j++) {
            sum += nums[j];
            if(sum==el) {
                maxx = max(maxx, j-i+1);
            }
            if(sum>el)
            break;
        }
    }

    return maxx;
}

int longestSubarray3(vector<int> nums, int el) {
    map<int, int> prefixSum; // (prefixSum, index);
    int length = 0, sum=0;

    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];
        if(sum==el) {
            length = max(length, i+1);
        }
        int rem = sum - el;

        if(prefixSum.find(rem) != prefixSum.end()) {
            length = max(length, i-prefixSum[rem]);
        }
        if(prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }

    return length;
}

int main() {
    vector<int> arr = {2,0,0,0,0,9};
    int k=9;

    cout << longestSubarray3(arr, k);

    return 0;
}