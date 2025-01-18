/*
Painter's Partition Problem

Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of 
the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. 
Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done 
of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sumArr(vector<int> arr) {
    int sum=0;
    for(int i=0; i<arr.size(); i++) sum+=arr[i];

    return sum;
}
int calcPainters(vector<int>& boards, int maxArea) {
    // returns number of painters req to paint all boards if each painter can paint at max of maxArea boards
    int painter = 1, currArea = 0;
    for(int i=0; i<boards.size(); i++) {
        if(currArea+boards[i] <= maxArea) {
            currArea += boards[i];
        } else {
            painter++;
            currArea = boards[i];
        }
    }

    return painter;
}
int minOfMax(vector<int>& boards, int k) {
    // returns min time req by k painters to paint boards
    int n=*max_element(boards.begin(), boards.end());

    // edge cases
    if(k>boards.size()) return -1;
    if(k==boards.size()) return n;

    int low=n, high=sumArr(boards);
    int ans=-1, mid;

    while(low<=high) {
        mid = low+(high-low)/2;

        int p = calcPainters(boards, mid);

        if(p<=k) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return ans;
}
int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    int k=2;
    cout << minOfMax(arr, k);

    return 0;
}