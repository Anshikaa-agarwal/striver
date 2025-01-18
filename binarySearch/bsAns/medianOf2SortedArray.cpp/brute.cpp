// Median of Two Sorted Arrays of different sizes
/*
Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. 
The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> mergeSortedArrays(vector<int>& x, vector<int>& y) {

    int n=x.size(), m=y.size();
    int i=0, j=0;
    vector<int> arr;

    while(i<n && j<m) {
        if(x[i] <= y[j]) {
            arr.push_back(x[i++]);
        } else {
            arr.push_back(y[j++]);
        }
    }

    // x array phle khtm hogya, add remaining elements of y
    while (i < n) {
        arr.push_back(x[i++]);
    } 

    // y phle khtm hogya, add remaining elements of x
    while (j < m) {
        arr.push_back(y[j++]);
    }

    return arr;
}
double median(vector<int>& x, vector<int>& y) {
    vector<int> arr = mergeSortedArrays(x, y);
    int n = arr.size(); 
    
    // If the merged array has an odd number of elements, return the middle element
    if (n % 2 != 0) {
        return arr[n / 2];
    }

    // If the merged array has an even number of elements, return the average of the two middle elements
    return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
}
int main() {
    vector<int> arr1 = {1,3,5};
    vector<int> arr2 = {2,4,6};

    cout << median(arr1, arr2);

    return 0;
}