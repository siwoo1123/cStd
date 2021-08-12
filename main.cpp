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

int n, m, r, c, s, k, visit[110][110], ans = 9999;

int dx[8] = {
        1, -1, 1, -1, 2, -2, 2, -2
}, dy[8] = {
        2, 2, -2, -2, 1, 1, -1, -1
};


void dfs(int x, int y, int step) {
    if(x < 0 || y < 0 || x >= n || y >= m || visit[x][y] <= step) return;
    visit[x][y] = step;

    for (int i = 0; i < 8; ++i) {
        dfs(x+dx[i], y+dy[i], step + 1);
    }
}


int main() {
    // SETTING
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);cin.tie(NULL);

    // INPUT
    cin >> n >> m >> r >> c >> s >> k;

    // WORK
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visit[i][j] = 1000000;
        }
    }
    dfs(r-1, c-1, 0);;

    // OUTPUT
    cout << visit[s-1][k-1] << "\n";

    //RETURN
    return 0;
}