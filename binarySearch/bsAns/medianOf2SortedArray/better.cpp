// Median of Two Sorted Arrays of different sizes
/*
Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. 
The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
double median(vector<int>& x, vector<int>& y) {
    // if there are odd elements, we need n/2 index and if there are even elements we need n/2 and (n/2)-1
    int n=x.size();
    int m=y.size();
    int i=0, j=0;
    int s = n+m;
    int ind1 = s/2;
    int ind2 = ind1-1;
    int count = 0, ind1el=-1, ind2el=-1;

    while(i<n && j<m) {
        if(x[i] < y[j]) {
            if(count == ind1) ind1el = x[i];
            if(count == ind2) ind2el = x[i];
            count++;
            i++;
        } else {
            if(count == ind1) ind1el = y[j];
            if(count == ind2) ind2el = y[j];
            count ++;
            j++;
        }
    }
    //arr y khtm hogya
    while(i<n) {
        if(count == ind1) ind1el = x[i];
        if(count == ind2) ind2el = x[i];
        count++;
        i++;
    }
    //arr x phle khtm hogya
    while(i<n) {
        if(count == ind1) ind1el = y[j];
        if(count == ind2) ind2el = y[j];
        count ++;
        j++;
    }

    if(s%2 == 0) {
        return (ind1el+ind2el)/2.0;
    } else return ind1el;
}
int main() {
    vector<int> arr1 = {1,3,5,9,10,11,12};
    vector<int> arr2 = {2,4,6};

    cout << median(arr1, arr2);

    return 0;
}