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

int n, m, r, c, s, k, janggi[110][110], ans;

int dx[8] = {
        1, -1, 1, -1, 2, -2, 2, -2
}, dy[8] = {
        2, 2, -2, -2, 1, 1, -1, -1
};


int dfs(int x, int y, int step) {
    if(x == s && y == k) return step;
    if(x < 0 || y < 0 || x >= n || y >= m) return 0;

    for (int i = 0; i < 8; ++i) {
        int dfsResult = dfs(x+dx[i], y+dy[i], step + 1);
        if(dfsResult) return dfsResult;
    }
}

int main() {
    // SETTING
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

    // INPUT
    cin >> n >> m >> r >> c >> s >> k;

    // WORK
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            janggi[i][j] = -1;
        }
    }

    ans = dfs(r-1, c-1, 0);;
    // OUTPUT
    cout << ans << "\n";

    //RETURN
    return 0;
}