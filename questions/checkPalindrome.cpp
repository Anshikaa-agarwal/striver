#include<iostream>
#include<string>
using namespace std;
bool checkPalindrome(string s) {
    int n = s.length();
    for(int i =0; i<n/2; i++) {
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
}
int main() {
    string s = "heeliuleeh";
    if(checkPalindrome(s)) cout << "yes";
    else cout << "no";
}