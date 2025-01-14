// Given an array of integers. From the array find sides with maximum paramter.
//Keep in mind the condition of triangle, a+b>c
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int perimeter(vector<int> arr, vector<int>& result) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int a, b, c;
    
    for(int i=n-1; i>=2; i--) {
        c = arr[i];
        b = arr[i-1];
        a = arr[i-2];

        if(a+b>c) {
            result.push_back(a);
            result.push_back(b);
            result.push_back(c);
            return a+b+c;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {1,2,3,1,2,6};
    vector<int> result;
    int p = perimeter(arr, result);
    if(p) {
        cout << "maximum perimeter = " << p << endl;
        cout << "Sides are: ";
        for(int i=0; i<result.size(); i++) cout << result[i] << " ";
    }
    else cout << "No triangle possible";
    return 0;
}