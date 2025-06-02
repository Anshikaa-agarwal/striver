#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void setMatrix0(vector<vector<int>> &mat) {
    // num of rows and cols
    int c = mat[0].size(); 
    int r = mat.size();

    // initialize 2 vectors - for row and col each
    vector<int> row(r, 0);
    vector<int> col(c, 0);

    // gives us arrays where count of 0 is more than 1
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(mat[i][j] == 0) {
                row[i]++;
                col[j]++;
            }
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(row[i] != 0 || col[j] != 0) 
            mat[i][j] = 0;
        }
    }
}
void printMatrix(vector<vector<int>> mat) {
    // num of rows and cols
    int c = mat[0].size(); 
    int r = mat.size();

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) 
        cout << mat[i][j] << " ";

        cout << endl;
    }
}
int main() {
    vector<vector<int>> matrix = {{0,1,2,0},
                                  {3,4,5,2},
                                  {1,3,1,5}};

    setMatrix0(matrix);
    printMatrix(matrix);

    return 0;
}