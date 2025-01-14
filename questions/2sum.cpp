/*Problem Statement: Given an array of integers arr[] and an integer target.
1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> twosum(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    int i,j, sum;
    i=0; j=arr.size()-1;
    while(i<j) {
        sum = arr[i]+arr[j];
        if(sum<target) i++;
        else if(sum>target) j--;
        else return {i,j};
    }
    return {-1,-1};
}
int main() {
    int target = 12;
    vector<int> arr = {1,2,3,4,5,6};
    vector<int> result = twosum(arr, target);
    if(result[0]!=-1) cout << "Target = arr[" << result[0] << "] + arr[" << result[1] << "] = " << arr[result[0]] << " + " << arr[result[1]] << " = " << target;
    else cout << "No such pair found";
    return 0;
}