// identify sorted half, pick min from it and discard it
#include<iostream>
#include<vector>
using namespace std;
int findMin(vector<int> arr) {
    int minn, ans = INT32_MAX;
    int low = 0, high = arr.size()-1, mid;

    while(low<=high) {
        mid = (low+high)/2;

        // find which half is sorted
        if(arr[low]<=arr[mid]) {
            //left is sorted
            minn = arr[low];
            low = mid+1;
        } else if(arr[mid]<=arr[high]) {
            //right is sorted
            minn = arr[mid];
            high = mid-1;
        }

        if(minn<ans) ans = minn;
    }
    return ans;
}
int main() {
    vector<int> arr = {7,8,1,2,3,4,5,6};
    int minn = findMin(arr);
    cout << minn;

    return 0;
}