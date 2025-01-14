/*Given an array arr[], with 0-based indexing, select any two indexes, i and j such that i < j. From the subarray arr[i...j], 
select the smallest and second smallest numbers and add them, you will get the score for that subarray. 
Return the maximum possible score across all the subarrays of array arr[].*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int sum(vector<int> arr, int start, int end) {
    int max1 = INT32_MIN;
    int max2 = INT32_MIN;
    for(int i=start+1; i<=end; i++) {
        if(arr[i]>max1) {
            max2 = max1;
            max1 = arr[i];
        }
        if(arr[i]>max2 && arr[i]<max1) max2 = arr[i];
    }
    return max1 + max2;
}
int score(vector<int> arr) {
    int s = 0;
    int score = INT32_MIN;
    for(int i=0; i<arr.size()-1; i++) {
        for(int j=i+1; j<arr.size(); j++) {
            s = sum(arr, i, j);
            if(s>score) score = s;
        }
    }
    return score;
}
int main() {
    vector<int> arr = {4, 3, 1, 5, 6};
    int s = score(arr);
    cout << s;
    return 0;
}