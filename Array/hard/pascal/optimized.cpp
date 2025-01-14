#include<iostream>
#include<vector>
using namespace std;
void pascal(int n) {
    for(int i=0; i<n; i++) {
        int value = 1;
        for(int j=0; j<=i; j++) {
            cout << value << " ";
            if (j < i)  // Prevent division by zero
            value = value * (i - j) / (j + 1);
        }
        cout << endl;
    }
}
int main() {
    pascal(5);
}