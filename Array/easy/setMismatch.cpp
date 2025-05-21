// 645. Set Mismatch

// You have a set of integers s, which originally contains all the numbers from 1 to n. 
// Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
// which results in repetition of one number and loss of another number.
#include<iostream>
#include<vector>
using namespace std;

vector<int> setMismatch(vector<int> &nums) {
    int missing = -1, dup = -1;
    for(int i=0; i<nums.size(); i++) {
        int val = abs(nums[i]);
        if(nums[val-1] < 0) {
            dup = val;
        }
        else {
            nums[val-1] *= -1;
        }
    }

    for(int i=0; i<nums.size(); i++) {
        if(nums[i] > 0) {
            missing = i+1;
            break;
        }
    }
    return {dup, missing};
}
void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}
int main() {
    vector<int> nums = {4,3,3,1,2};
    vector<int> result = setMismatch(nums);

    printArr(result);
    return 0;
}