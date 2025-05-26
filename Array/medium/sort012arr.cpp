#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int> &nums) {
    int low = 0, mid = 0, high = nums.size()-1;
    while(mid<=high) {
        if(nums[mid] == 1) 
        mid++;
        else if(nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);
        }
        else {
            swap(nums[mid], nums[high--]);
        }
    }
}

void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}

int main() {
    vector<int> arr = {0,0,2,1,0,2,0};
    sort012(arr);
    printArr(arr);

    return 0;
}