/*
Problem Statement: You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses 
to make a single bouquet.
Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countBouquets(vector<int>& arr, int k, int x) {
    //this func gives how many bouquets can we make of k flowers on xth

    int count=0, sum=0;

    for(int i=0; i<arr.size(); i++) {
        if(arr[i]<=x) sum++;
        else sum=0;

        if(sum==k) {
            count++;
            sum=0;
        }
    }
    return count;
}
int calcDays(vector<int> &arr, int k, int m) {
    int low=1, high=*max_element(arr.begin(), arr.end()), mid, ans=-1;

    while(low<=high) {
        mid=low+(high-low)/2;
        int b=countBouquets(arr, k, mid); //gives how many bouquets can we make on (mid)th day.

        // if b>=m, mid can be a possible ans but we can look for a smaller day
        if(b>=m) {
            ans=mid;
            high=mid-1;
        } else low=mid+1;
    }
    return ans;
}
int main() {
    vector<int> arr = {7,7,7,7,13,11,12,7};
    cout << calcDays(arr, 3, 2);
}