// Left shift array by 1 place
#include<iostream>
#include<vector>
using namespace std;

void leftShift(vector<int> &nums) {
    int temp = nums[0], i=0;

    for(i=0; i<nums.size()-1; i++) {
        nums[i] = nums[i+1];
    }

    nums[i] = temp;
}
void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}
int main() {
    vector<int> nums = {1,2,3,4,5};
    leftShift(nums);
    printArr(nums);

    return 0;
}
