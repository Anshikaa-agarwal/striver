// Merge Two Sorted Arrays
#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> nums1, vector<int> nums2) {

    vector<int> result;
    int n = nums1.size();
    int m = nums2.size();
    int i=0, j=0;

    while(i<n && j<m) {
        if(nums1[i] < nums2[j]) 
        result.push_back(nums1[i++]);

        else
        result.push_back(nums2[j++]);
    }

    while(i<n) 
    result.push_back(nums1[i++]);

    while(j<m)
    result.push_back(nums2[j++]);

    return result;
}
void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}
int main() {
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {2,3,4,4,5};

    vector<int> result = merge(nums1, nums2);

    printArr(result);

    return 0;
}