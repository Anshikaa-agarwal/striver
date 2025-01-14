#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> twoSum(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    int i=0, j=arr.size()-1;
    while(i<j) {
        int sum = arr[i] + arr[j];
        if(sum<k) i++;
        else if(sum>k) j--;
        else return {i,j};
    }
    return {-1, -1};
}
int main() {
    vector<int> arr = {1,4,2,0,9,7};
    int k = 12;
    vector<int> result = twoSum(arr, k);
    if(result[0] != -1) cout << "Sum of K = " << k << " occurs at index " << result[0] << " and " << result[1] << endl;
    else cout << "Element not found."; //this code will return new indices rather than original
    return 0; 
}