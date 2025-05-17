// Shift 0's to end of array
#include<iostream>
#include<vector>
using namespace std;

void shiftZero(vector<int> &nums) {
    int i=0;

    for(int j=0; j<nums.size(); j++) {
        if(nums[j] != 0) {
            nums[i++] = nums[j];
        }
    }

    while(i<nums.size()) {
        nums[i++] = 0;
    }
}
void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}
int main() {
    vector<int> arr = {1,0,9,0,0,2,0,3,4,0,1};
    shiftZero(arr);
    printArr(arr);
}