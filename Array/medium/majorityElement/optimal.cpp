// Moore's Voting Algorithm - candidate identification and candidate verifivation
#include<iostream>
#include<vector>
using namespace std;
// candidate identification
int findCandidate(vector<int> arr) {
    int element, count = 0;
    for(int i=0; i<arr.size(); i++) {
        if(count==0) {
            element = arr[i];
        }
        if(arr[i]==element) count++;
        else count--;
    }
    return element;
}
// candidate verification
bool isMajority(vector<int> arr, int candidate) {
    int count = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == candidate) count++;
    }
    return count > arr.size() / 2;
}
int main() {
    vector<int> arr = {1,1,1,1,2,3,4,4,4,4,4,4,4,4,4};
    int element = findCandidate(arr);
    if(isMajority(arr, element)) cout << "Majority element is " << element << endl;
    else cout << "No majority element.";
    return 0;
}