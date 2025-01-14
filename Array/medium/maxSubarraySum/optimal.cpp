// KADANE's Algorithm
#include<iostream>
#include<vector>
using namespace std;
int maxSubarraySum(vector<int> arr) {
    int sum=0, maxx = INT16_MIN;

    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];
        if(sum>maxx) maxx = sum;
        if(sum<0) sum=0;
    }

    return maxx;
}
int main() {
    vector<int> arr = {-2,-1,-3,-4};
    cout << maxSubarraySum(arr);
    return 0;
}