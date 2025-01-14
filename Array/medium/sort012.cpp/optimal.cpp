// Dutch National Flag Algorithm
// Initiate 3 variables - low, mid and high
// 0 to low-1 : 0; low - mid-1: 1, mid to high: 0/1/2 randomly; high+1 to n-1: 2

#include<iostream>
#include<vector>
using namespace std;
void swap(int &x, int &y) {
    //x=3, y=7
    x=x+y; //x=10
    y=x-y; //y=10-7=3
    x=x-y; //x=10-3=7
}
void sort0123(vector<int> &arr) {
    int l=0, m=0, h=arr.size()-1;
    while (m<=h) {
        if(arr[m]==0) swap(arr[l++], arr[m++]);
        else if(arr[m]==1) m++;
        else swap(arr[m], arr[h--]); 
    }
}
void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}
int main() {
    vector<int> arr = {0,1,1,2,0,2,1,0,1};
    sort0123(arr);
    printArr(arr);
    return 0;
}