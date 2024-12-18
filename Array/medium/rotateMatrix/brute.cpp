// Rotate Matrix anti-clockwise by 90 degree

//Problem statement: Given a matrix, your task is to rotate matrix anti-clockwise by 90 degrees.
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> rotate90(vector<vector<int>> matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> result(col, vector<int>(row));

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            result[col-j-1][i] = matrix[i][j];
        }
    }
    return result;
}
int main() {
    vector<vector<int>> mat = {{1,2,3},
                            {4,5,6},
                            {7,8,9}};

    vector<vector<int>> result = rotate90(mat);

    cout << "Original matrix: " << endl;
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Rotated matrix: " << endl;
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}