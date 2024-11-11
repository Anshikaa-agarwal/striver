// Moore's Voting Algorithm - candidate identification and candidate verifivation
#include<iostream>
#include<vector>
using namespace std;
int majority(vector<int> arr) {
    int element, count=0, c=0;
    for(int i=0; i<arr.size(); i++) {
        if(count == 0) {
            element = arr[i];
            count++;
        }
        else {
            if(arr[i]==element) count++;
            else count--;
        }
    }
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]==element) c++;
    }
    if(c>arr.size()/2) return element;
    else return -1;
}
int main() {
    vector<int> arr = {1,1,1,1,2,3,4,4,4,4,4,4,4};
    cout << "Majority element is " << majority(arr);
    return 0;
}