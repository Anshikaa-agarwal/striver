#include<iostream>
#include<vector>
using namespace std;

void rotateK(vector<int> &nums, int k) {
    vector<int> temp;
    k = k%nums.size();
    
    for(int i=0; i<k; i++) 
    temp.push_back(nums[i]);

    int i=0, j=0;
    for(i=0; i<nums.size()-k; i++) {
        nums[i] = nums[k+i];
    }

    for(i; i<nums.size(); i++) {
        nums[i] = temp[j++];
    }
}
void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}
int main() {
    vector<int> nums = {1,2,3,4,5};
    rotateK(nums, 2);
    printArr(nums);

    return 0;
}
