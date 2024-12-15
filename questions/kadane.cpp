/*Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.
*/
#include<iostream>
#include<vector>
using namespace std;
int kadane(vector<int> arr, vector<int>& result) {
    int maxx = INT32_MIN;
    int sum = 0, start = 0, end = 0;
    int temp_start = 0;

    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];
        if(sum>maxx) {
            maxx = sum;
            end = i;
            start = temp_start;
        }
        if(sum<0) {
            sum = 0;
            temp_start=i+1;
        }
    }
    for(int i=start; i<=end; i++) {
        result.push_back(arr[i]);
    }
    return maxx;
}
int main() {
    vector<int> arr = {1,2,-8,2,4,6,-3,4,5,9,-1};
    vector<int> result;
    int sum = kadane(arr, result);
    cout << "Maximum sum is " << sum << endl;
    cout << "Resulting array : ";
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}