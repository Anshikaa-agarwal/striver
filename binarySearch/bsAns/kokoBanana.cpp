/*
Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. 
An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains 
less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.
*/

/*
Example 1:
Input Format:
 N = 4, a[] = {7, 15, 6, 3}, h = 8
Result:
 5
Explanation:
 If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles. 
*/

// Approach: take an array from 1 to max element from piles. apply bs there, if arr[mid] takes more than h hours, move right, else move left.

#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
long long calcHours(vector<int> piles, int k) {
    // koko eats k bananas per hour
    long long sum=0;

    for(int i=0; i<piles.size(); i++) {
        if(piles[i]<=k) sum+=1;
        else {
            sum=sum+ceil((double)piles[i]/k);
        }
    }
    return sum;
}
int kokoBanana(vector<int> piles, int h) {
    // define an array from 1 to max element of piles
    int low=1, high=*max_element(piles.begin(), piles.end()), mid, ans;

    //apply bs there, if calculated hours is more than h, move right, else left
    while(low<=high) {
        mid=low+(high-low)/2;
        long long time = calcHours(piles, mid);

        if(time<=h) {
            // agar time h se kam lag rha hai to there is a possiblity ki mid ans ho, but there could be a smaller value, therefore smaller value than mid
            ans=mid;
            high=mid-1;
        }
        else if(time>h) {
            //right search, take a greater value than h
            low=mid+1;
        }
    }
    return ans;
}
int main() {
    int h=1000000000;
    vector<int> arr={805306368,805306368,805306368};

    cout << kokoBanana(arr, h);

    return 0;
}