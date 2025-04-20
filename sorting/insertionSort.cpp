#include<vector>
#include<iostream>

using namespace std;

void swapp(int &x, int &y) {
    if(&x == &y) return;

    x=x+y;
    y=x-y;
    x=x-y;
}

void insertionSort(vector<int> &arr) {
    for(int i=1; i<arr.size(); i++) {
        //assuming that 0th index is at it's place
        if(arr[i]<arr[i-1]) {
            //array is unsorted and we need to bring the element to it's correct place.
            int element = arr[i];
            int j=i;
            while(arr[j] < arr[j-1] && j>0) {
                swapp(arr[j], arr[j-1]);
                j--;
            }
        }
    }
}

void printArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}

int main() {
    vector<int> arr = {14,19,40,32,89,-3};
    insertionSort(arr);
    printArr(arr);
    return 0;
}