// use linear search, as soon as we find arr[i]<arr[i+1] return arr[i+1]

#include<iostream>
#include<vector>
using namespace std;
int minSorted(vector<int> arr) {
    for(int i=0; i<arr.size()-1; i++) {
        if(arr[i]>arr[i+1]) return arr[i+1];
    }
    return -1;
}
int main() {
    vector<int> arr = {4,5,6,7,8,1,2,3};
    int minn = minSorted(arr);
    cout << minn;
}