// Rotate Matrix anti-clockwise by 90 degree

//Problem statement: Given a matrix, your task is to rotate matrix anti-clockwise by 90 degrees.
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> rotate90(vector<vector<int>> matrix) {
    
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> result(cols, vector<int>(rows));

    for(int i=cols-1; i>=0; i--) {
        for(int j=rows-1; j>=0; j--) {
             result[cols - j - 1][i] = matrix[i][j];
        }
    }

    return result;
}
int main() {
    vector<vector<int>> mat = {{1,2,3},
                            {4,5,6},
                            {7,8,9}};

    vector<vector<int>> result = rotate90(mat);
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}