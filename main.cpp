/*
-----------------
| | | | | | | | |
-----------------
| | |  장기  | | |
-----------------
| | 2020.8.10 | |
-----------------
| | | | ~ | | | |
-----------------
| | 2020.8.12 | |
-----------------
| | | | | | | | |
-----------------
*/

#include <iostream>

using namespace std;

int n, m, r, c, s, k, ans, janggi[110][110];

int main() {
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    cin >> n >> m >> r >> c >> s >> k;
    janggi[r][c] = 1;
    janggi[s][k] = 2;
}