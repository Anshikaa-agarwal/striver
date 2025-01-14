// sort array and find return middle element.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int majority(vector<int> arr) {
    int mid = (arr.size()-1)/2;
    sort(arr.begin(), arr.end());
    return arr[mid];
}
int main() {
    vector<int> arr = {1,1,1,1,2,3,4,4,4,4,4,4,4};
    cout << "Majority element is " << majority(arr);
    return 0;
}