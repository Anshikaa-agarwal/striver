#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int bs(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    int low = 0;
    int high = arr.size()-1;

    while(low<high) {
        int mid = low + (high-low)/2;
        if(arr[mid]==target) return mid;
        if(target>arr[mid]) { //right side
            low = mid+1;
        } 
        else {
            //left search
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {4,8,0,9,11,7,3};
    int target = 17;
    int search = bs(arr, target);
    if(search==-1) cout << "Element not found.";
    else cout << "Element found." << endl;

    return 0;
}