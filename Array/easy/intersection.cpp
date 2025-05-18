// Find intersection of 2 sorted arrays
#include<iostream>
#include<vector>
using namespace std;

vector<int> intersection(vector<int> nums1, vector<int> nums2) {
    int i=0, j=0;
    int n=nums1.size();
    int m=nums2.size();
    vector<int> result;

    while(i<n && j<m) {
        if(nums1[i] < nums2[j]) i++;
        else if(nums2[j] < nums1[i]) j++;
        else {
            result.push_back(nums1[i]);
            i++;
            j++;
        }
    }

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

    vector<int> result = intersection(nums1, nums2);

    printArr(result);

    return 0;
}