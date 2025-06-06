// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.
// Upper bound: Smallest index s.t arr[i] > x

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int upperBound(vector<int> &nums, int x) {
    int low=0, high=nums.size()-1;
    int ans = nums.size(), mid;

    while(low<=high) {
        mid = low+(high-low)/2;
        if(nums[mid] > x) {
            ans = mid;
            high=mid-1;
        }
        else 
        low=mid+1;
    }

    return ans;
}
int main() {
    vector<int> nums = {1, 3, 3, 5, 8, 9};
    int x;
    
    cout << "Enter the value to find upper bound for: ";
    cin >> x;
    
    int index = upperBound(nums, x);
    
    if (index == nums.size()) {
        cout << "No element found greater than " << x << endl;
    } else {
        cout << "Upper bound of " << x << " is at index " << index 
             << ", value = " << nums[index] << endl;
    }

    return 0;
}