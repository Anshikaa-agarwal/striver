// Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.
// arr[] = {1,1,2,2,3,3,4,5,5,6,6}, answer = 4

#include<iostream>
#include<vector>
using namespace std;
int singleOccurence(vector<int> arr) {
    int low=0, high=arr.size()-1, mid;

    while(low<=high) {
        if (high == 0) return arr[0];

        mid=(low+high)/2;

        if ((mid == 0 || arr[mid-1] != arr[mid]) && (mid == arr.size()-1 || arr[mid] != arr[mid+1])) {
            return arr[mid];
        }

        if(arr[mid-1]==arr[mid]) {
            //element found in left

            //if even elements are present(odd index), eliminate left half
            if((mid-low)%2 == 0) high=mid-1;
            else low=mid+1;
        }
        else if(arr[mid]==arr[mid+1]) {
            //element found in right

            if((high-mid)%2!=0) {
                //eliminate right half
                high=mid-1;
            } else low=mid+1;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {2,2,3};
    int element = singleOccurence(arr);

    cout << element;

    return 0;
}