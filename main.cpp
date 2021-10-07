#include <iostream>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

int n, m, front, rear, visit[110][110][5], ans;
struct {int n, m, s;} s, f;
struct Q {
    int n, m, s, b;
} que[12100];

void push(Q ipt) {
    if(ipt.n >= n || ipt.m >= m || ipt.n < 0 || ipt.m < 0 || ipt.s > 4 || ipt.s <= 0 || visit[ipt.n][ipt.m][ipt.s]) return;
    visit[ipt.n][ipt.m][ipt.s] = 1;
    que[rear++] = ipt;
}

void bfs() {
    push({s.n, s.m, s.s, -1});
    while (front < rear) {
        Q h = que[front];
        if(h.n == f.n && h.m == f.m && h.s == f.s) {
            for (int i = front; i > 0; i=que[i].b) {
                ans++;
            }
            return;
        }
        if(h.s == 1) {
            push({h.n, h.m+1, h.s, front});
            push({h.n, h.m+2, h.s, front});
            push({h.n, h.m+3, h.s, front});
            push({h.n, h.m, 4, front});
            push({h.n, h.m, 3, front});
        } else if(h.s == 2) {
            push({h.n, h.m-1, h.s, front});
            push({h.n, h.m-2, h.s, front});
            push({h.n, h.m-3, h.s, front});
            push({h.n, h.m, 4, front});
            push({h.n, h.m, 3, front});
        } else if(h.s == 3) {
            push({h.n+1, h.m, h.s, front});
            push({h.n+2, h.m, h.s, front});
            push({h.n+3, h.m, h.s, front});
            push({h.n, h.m, 1, front});
            push({h.n, h.m, 2, front});
        } else if(h.s == 4) {
            push({h.n-1, h.m, h.s, front});
            push({h.n-2, h.m, h.s, front});
            push({h.n-3, h.m, h.s, front});
            push({h.n, h.m, 1, front});
            push({h.n, h.m, 2, front});
        }
        front++;
    }
}

int main() {
    int ipt[110][110];
    setting;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ipt[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(ipt[i][j] == 1) {
                visit[i][j][1] = 1;
                visit[i][j][2] = 1;
                visit[i][j][3] = 1;
                visit[i][j][4] = 1;
            }
        }
    }
    cin >> s.n >> s.m >> s.s;
    cin >> f.n >> f.m >> f.s;
    bfs();
    cout << ans << "\n";
    return 0;
}
