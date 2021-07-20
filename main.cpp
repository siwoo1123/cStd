#include <iostream>
#define nil NULL
#define DEBUG
using namespace std;

int paper[110][110], n;

void painting(int a, int b) {
    for (int i = a; i < a+10; ++i) {
        for (int j = b; j < b+10; ++j) {
            paper[i][j] = 1;
        }
    }
}

void output(int x, int y, char md) {
    if(md == '*') {
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                if(paper[i][j] == 1) cout << "* ";
                else cout << "  ";
            }
            cout << "\n";
        }
    } else {
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                cout << paper[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nil);
    cout.tie(nil);

    cin >> n;
    int o, t;
    for (int i = 1; i <= n; ++i) {
        cin >> o >> t;
        painting(o, t);
    }
    #ifdef DEBUG
    output(30, 30, '*');
    output(30, 30, 'n');
    #endif
}