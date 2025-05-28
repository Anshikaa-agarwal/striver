// Stock buy and sell
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &nums) {
    int minn = INT32_MAX;
    int profit = 0;

    for(int i=0; i<nums.size(); i++) {
        
        minn = min(minn, nums[i]);
        profit = max(profit, nums[i]-minn);
    }

    return profit;
}

int main() {
    vector<int> nums = {7,4,5,3,6,4};
    cout << maxProfit(nums);

    return 0;
}