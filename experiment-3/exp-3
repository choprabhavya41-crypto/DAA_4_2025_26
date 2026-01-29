#include <bits/stdc++.h>
using namespace std;

int n;
char board[10][10];  

bool col[10];
bool rightD[20];
bool leftD[20];

bool solve(int row) {
    if (row == n)
        return true;

    for (int c = 0; c < n; c++) {
        if (!col[c] && !rightD[row + c] && !leftD[n - 1 + c - row]) {

            board[row][c] = 'Q';
            col[c] = rightD[row + c] = leftD[n - 1 + c - row] = true;

            if (solve(row + 1))
                return true;

            board[row][c] = '.';
            col[c] = rightD[row + c] = leftD[n - 1 + c - row] = false;
        }
    }
    return false;
}

int main() {
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = '.';

    if (!solve(0)) {
        cout << "No solution exists";
        return 0;
    }

    cout << "Solution:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
