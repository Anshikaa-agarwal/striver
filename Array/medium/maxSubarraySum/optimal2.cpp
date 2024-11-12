#include <bits/stdc++.h>
using namespace std;
    int MaxSum(vector<int> &arr) {
        // Your code goes here
        int sum=0, maxx = arr[0], tempStart = 0, start = 0, end = 0;
        
        for(int i=0; i<arr.size(); i++) {
            sum += arr[i];
            if(sum>maxx) {
                maxx = sum;
                start = tempStart;
                end = i;
            }
            if(sum<0) {
                sum=0;
                tempStart = i+1;
            }
        }
        return maxx;
    }
int main() {
    vector<int> arr = {1,2,3};
    cout << MaxSum(arr);
}
