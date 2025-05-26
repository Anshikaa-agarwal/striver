#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool twoSum(vector<int> nums, int k) {
    map<int, int> mpp;

    for(int i=0; i<nums.size(); i++) {
        if(mpp.find(nums[i]) != mpp.end())
        return true;
        else {
            mpp[k-nums[i]] = i;
        }
    }
    return false;
}

bool twoSum2(vector<int> nums, int k) {
    sort(nums.begin(), nums.end());
    int i=0, j=nums.size()-1;

    while(i<j) {
        int sum = nums[i] + nums[j];
        if(sum>k) j--;
        else if(sum < k) i++;
        else return true;
    }

    return false;
}
int main() {
    vector<int> nums = {2,6,5,8,11};
    int target =19;

    cout << twoSum2(nums, target);

    return 0;
}