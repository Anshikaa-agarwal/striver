#include<iostream>
#include<vector>
using namespace std;

void removeDuplicates(vector<int> &nums) {
    int i=0; 
    for(int j=1; j<nums.size(); j++) {
        if(nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
    }
    cout << i+1;
}

int main() {
    vector<int> nums = {1,1,2,2,2,3,3,4,4,5,6,7,7,7,7};
    removeDuplicates(nums);

    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}