/*
Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.
*/

/*
Example 1:  N = 6, k = 4, arr[] = {0,3,4,7,10,9}
            Result = 3
            Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. 
            Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool minDistance(vector<int> &arr, int k, int x) {
    // func will return if it is possible to keep min distance of x b/w k cows in sorted array

    vector<int> pos(k); //define a vector of size k to keep in track the positions of cow
    int j=1; // keeps track of indices of cow's pos

    pos[0] = arr[0]; // place 1st cow at 0th index

    for(int i=1; i<arr.size(); i++) {
        if((arr[i]-pos[j-1])>=x) {
            // agr distance atleast x hai to we can place a cow at this pos
            pos[j++]=arr[i];
        }
        if(j==k) return true;
    }
    
    return false;
} 
int maxOfMin(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int maxx = arr[arr.size()-1];
    int minn = arr[0];

    int low=1, high=maxx-minn;
    int mid, ans=-1;

    while(low<=high) {
        mid=low+(high-low)/2;
        bool dist = minDistance(arr, k, mid); //tells if it is possible to keep a min distance of 'mid' b/w k cows

        // if it is possible, we may look for an even greater distance
        if(dist) {
            ans = mid;
            low=mid+1;
        } else high=mid-1;
    }
    return ans;
}
int main() {
    vector<int> arr = {4,2,1,3,6};
    int k=2;
    cout << maxOfMin(arr, k);

    return 0;
}