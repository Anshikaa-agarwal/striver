#include<iostream>
#include<vector>
using namespace std;

int ncr(int n, int r) {
    int result=1;

    for(int i=0; i<r; i++) {
        result = result*(n-i);
        result = result/(i+1);
    }

    return result;
}
// print element of row r, col c
int variation1(int r, int c) {
    return ncr(r-1, c-1);
}
// print rth row
void variation2(int r) {
    int res = 1;
    for(int i=0; i<r; i++) {
        if(i==0) {
            cout << res << " ";
            continue;;
        }
        res = res*(r-i);
        res = res /(i);

        cout << res << " ";
    }
}


int main() {
    cout << ncr(4,2) << endl;
    cout << ncr(5,2) << endl;
    cout << ncr(6,3) << endl;

    // variation1
    cout << variation1(5,2) << endl;

    // print row
    variation2(5);
}