// First and last occurrence in a sorted array.

// Approach: i) find lower bound
//          ii) then, linear spearch
#include<iostream>
#include<vector>
using namespace std;
int ub(vector<int> arr, int x) {
    int low=0, high = arr.size()-1, ans = arr.size();
    
    while(low<=high) {
        int mid = low+(high-low)/2;
        if(arr[mid]>=x) {
            // move left
            ans = mid;
            high = mid - 1;
        } else {
            // move right
            low = mid+1;
        }
    }
    if(ans<arr.size() && arr[ans]>=x) return ans;
    else return -1;
}
vector<int> occurrence(vector<int> arr, int target) {
    int ans = ub(arr, target);
    int end = ans;
    if(ans==-1) return {-1,-1};

    for(int i=ans+1; i<=arr.size(); i++) {
        if(arr[i]==target) end++;
    }

    return {ans, end};
}
int main() {
    vector<int> arr = {1,2,3,13,13,13,40,45,70};
    int target = 13;
    vector<int> result = occurrence(arr, target);
    cout << result[0] << " " << result[1] << " ";

    return 0;
}