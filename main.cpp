#include <iostream>
using namespace std;

int B[11][11];

void Flip(int R, int C) {
    for (int i=0; i<R/2; ++i) {
        for (int j=0; j<C; ++j) {
            swap(B[R-1-i][j],B[i][j]);
        }
    }
}

int temp[11][11];

void Rotate(int &R, int &C) {
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            temp[C-1-j][i] = B[i][j];
        }
    }
    swap(R,C);
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            B[i][j] = temp[i][j];
        }
    }
}

int main() {
    int r,c,m;
    cin >> r >> c >> m;
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            cin >> B[i][j];
        }
    }
    int ops[11];
    for (int i=0; i<m; ++i) {
        cin >> ops[i];
    }
    for (int i=m-1; i>=0; --i) {
        if (ops[i] == 1) {
            Flip(r,c);
        }else{
            Rotate(r,c);
        }
    }
    cout << r << " " << c << endl;
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            if (j < c-1) {
                cout << B[i][j] << " ";
            }else{
                cout << B[i][j] << endl;
            }
        }
    }
    return 0;
}