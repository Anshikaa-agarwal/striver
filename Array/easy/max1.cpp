// Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.
#include<iostream>
#include<vector>
using namespace std;

int max1(vector<int> &nums) {
    int count = 0, maxx = 0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == 1) count++;
        else if (nums[i] == 0) {
            if(count > maxx) 
            maxx = count;
            count = 0;
        }
    }
    if(count > maxx) 
    maxx = count;
    
    return maxx;
}
int main() {
    vector<int> arr = {1 , 1, 0, 1, 1, 1};
    cout << max1(arr);

    return 0;
}