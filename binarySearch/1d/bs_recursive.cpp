// Implement binary search using recursion
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int bs_recursive(vector<int> arr, int target, int low, int high) {
    if(low>high) return -1;

    int mid = low + (high-low)/2;
    if(arr[mid]==target) return mid;
    if(target<arr[mid]) return bs_recursive(arr, target, low, mid-1);
    else return bs_recursive(arr, target, mid+1, high);
}
bool bs(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    int index = bs_recursive(arr, target, 0, arr.size()-1);
    if(index==-1) return false;
    else return true;
}
int main() {
    vector<int> arr = {4,8,0,9,11,7,3};
    int target = 7;

    if(bs(arr, target)) cout << "found";
    else cout << "not found";

    return 0;
}