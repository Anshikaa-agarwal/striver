// Problem Statement: You are given a positive integer n. Your task is to find and return its square root. 
// If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

#include<iostream>
#include<vector>
using namespace std;
int sqrt(int x) {
    int ans;
    for(int i=1; i<=x/2; i++) {
        if(i*i<=x) ans=i;
        else break;
    }
    return ans;
}
int main() {
    int x=28;
    cout << "Square root of " << x << " is " << sqrt(x);
}