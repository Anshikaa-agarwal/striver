// Kadane's Algorithm
#include<iostream>
#include<vector>
using namespace std;

int maxSumm(vector<int> &nums) {
    int maxSum = INT32_MIN;
    int sum = 0;

    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];
        if(sum > maxSum)
        maxSum = sum;

        if(sum < 0)
        sum = 0;
    }

    return maxSum;
}

int main() {
    vector<int> arr = {0};
    cout << maxSumm(arr);

    return 0;
}