#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high) {
        if(arr[left]<arr[right])
        temp.push_back(arr[left++]);
        else
        temp.push_back(arr[right++]);
    }

    while(left<=mid) temp.push_back(arr[left++]);
    while(right<=high) temp.push_back(arr[right++]);

    for(int i=low; i<=high; i++) 
    arr[i] = temp[i-low];
}

void mergeSort(vector<int> &arr, int low, int high) {
    if(low>=high) return;

    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);
}
void printArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}

int main() {
    vector<int> arr = {14,19,40,32,89,-3};
    mergeSort(arr, 0, arr.size()-1);
    printArr(arr);
    return 0;
}