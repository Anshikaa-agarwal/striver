#include<iostream>
#include<vector>
using namespace std;

void ls(vector<int> nums, int element) {
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == element) {
            cout << "Element found at index " << i << endl; 
            return;
        }
    }
    cout << "Element not found";
}
int main() {
    vector<int> nums = {1,3,5,7,90,3,1,9};
    ls(nums, 11);
}