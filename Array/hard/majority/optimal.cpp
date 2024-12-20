// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.
 
// Moore's Voting Algorithm updated

// Approach: At maximum, there can be two such elements present in the array which occur more than n/3 times.
#include<iostream>
#include<vector>
using namespace std;
vector<int> majority(vector<int> arr) {
    int el1, el2;
    int c1 = 0, c2 = 0;

    for(int i=0; i<arr.size(); i++) {
        if(c1 == 0 && arr[i]!=el2) {
            el1 = arr[i];
            c1++;
        }
        else if(c2 == 0 && arr[i]!=el1) {
            el2 = arr[i];
            c2++;
        }
        else if(arr[i]==el1) c1++;
        else if(arr[i]==el2) c2++;
        else {
            c1--;
            c2--;
        }
    }

    vector<int> result;
    result.push_back(el1);
    result.push_back(el2);

    return result;
}
vector<int> verification(vector<int> arr, vector<int> result) {
    int f1=0, f2=0;
    vector<int> verify;

    for(int i=0; i<arr.size(); i++) {
        if(arr[i]==result[0]) f1++;
        else if(arr[i]==result[1]) f2++;
    }

    if(f1>arr.size()/3) verify.push_back(result[0]);
    if(f2>arr.size()/3) verify.push_back(result[1]);

    return verify;
}
int main() {
    vector<int> arr = {1,1,1,3,4,3,3};
    vector<int> result = majority(arr);
    vector<int> verify = verification(arr, result);

    for(int i=0; i<verify.size(); i++) {
        cout << "Majority element: " << verify[i] << endl;
    }
}