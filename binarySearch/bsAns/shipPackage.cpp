// Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. 
// The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the 
// same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.

/*
Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like 
(2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
*/

// Approach: Our ans lies in range max(weights[]), sum(weight[]) because min weight capacity will be atleast the max weight

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int calcDays(vector<int>& arr, int weight) {
    int days=1;
    int sum=0;

    for(int i=0; i<arr.size(); i++) {
        
        if(sum+arr[i]>weight) {
            days++;
            sum=0;
        }
        sum+=arr[i];
    }
    return days;
}
int sum(vector<int>& arr) {
    int sum=0; 
    for(auto it:arr)  sum+=it;
    return sum;
}
int capacity(vector<int>& wt, int days) {
    int low=*max_element(wt.begin(), wt.end()), high=sum(wt), mid, ans=0;

    while(low<=high) {
        mid=low+(high-low)/2;
        int d=calcDays(wt, mid);
        
        if(d<=days) {
            ans=mid;
            high=mid-1;
        } else low=mid+1;
    }
    return ans;
}
int main() {
    vector<int> wt = {1,2,3,1,1};
    int days=4;
    cout << capacity(wt, days);
}