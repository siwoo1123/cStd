#include <iostream>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)

using namespace std;

int n, m, arr[120][120], ans, cnt, loop, visit[120][120];

void visit_clear();

void count() {
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(arr[i][j] == 1) cnt++;
        }
    }
}

void clear() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(arr[i][j] == 2) arr[i][j] = 0;
        }
    }
}

void dfs(int x, int y) {
    if(arr[x][y] || x < 0 || y < 0 || x >= n || y >= m || visit[x][y]) return;
    //cout << "x: " << x << ", y:" << y << "\n";
    // 제거 할 치즈를 2로 표시.
    if(x+1 < n && arr[x+1][y]==1) arr[x+1][y] = 2;
    if(x-1 >= 0 && arr[x-1][y]==1) arr[x-1][y] = 2;
    if(y+1 < m && arr[x][y+1]==1) arr[x][y+1] = 2;
    if(y-1 >= 0 && arr[x][y-1]==1) arr[x][y-1] = 2;

    visit[x][y] = 1;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
    visit[x][y] = 1;
}

int main() {
    setting;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    count();
    while (1) {
        ans = cnt;
        loop++;
        dfs(0, 0);
        clear();
        count();
        visit_clear();
        if(cnt == 0) break;
    }
    cout << loop << "\n";
    cout << ans << "\n";
    return 0;
}

void visit_clear() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visit[i][j] = 0;
        }
    }
}
