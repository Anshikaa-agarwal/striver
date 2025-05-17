#include<iostream>
#include<vector>

using namespace std;

bool checkSorted(vector<int> nums) {
    if(nums.size() == 1) return true;
    
    for(int i=1; i<nums.size(); i++) {
        if(nums[i] < nums[i-1])
        return false;
    }
    return true;
}

int main() {
    vector<int> nums = {4,1};
    cout << checkSorted(nums);
}