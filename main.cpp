#include <iostream>
//#define DEBUG
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

int n, m, front, rear, visit[110][110], ans;
struct Q {
    int n, m, s, b;
} que[12100];
struct Sf {
    int n, m, s;
} s, f;

void turn(char dir, int bf) {
    Q h = que[bf];
    if(dir == 'r') {
        if(que[bf].s == 1) {
            que[rear++] = {h.n, h.m, 3, bf};
        } else if(que[bf].s == 2) {
            que[rear++] = {h.n, h.m, 4, bf};
        } else if(que[bf].s == 3) {
            que[rear++] = {h.n, h.m, 2, bf};
        } else if(que[bf].s == 4) {
            que[rear++] = {h.n, h.m, 1, bf};
        }
    } else if(dir == 'l') {
        if(que[bf].s == 1) {
            que[rear++] = {h.n, h.m, 4, bf};
        } else if(que[bf].s == 2) {
            que[rear++] = {h.n, h.m, 3, bf};
        } else if(que[bf].s == 3) {
            que[rear++] = {h.n, h.m, 1, bf};
        } else if(que[bf].s == 4) {
            que[rear++] = {h.n, h.m, 2, bf};
        }
    }
}
#ifdef DEBUG
FILE *a = fopen("/Users/apple/dev/c/CLion/c/main.txt", "w");
void pV() {
    fprintf(a, "============================\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fprintf(a, "%d ", visit[i][j]);
        }
        fprintf(a, "\n");
    }
}
#endif
void go(int k, int bf) {
    Q h = que[bf];
    if(que[bf].s == 1) {
        if(h.n >= n || h.m+k >= m || h.n < 0 || h.m+k < 0 || visit[h.n][h.m+k]) return;
        que[rear++] = {h.n, h.m+k, h.s, bf};
        visit[h.n][h.m+k] = 2;
    } else if(que[bf].s == 2) {
        if(h.n >= n || h.m-k >= m || h.n < 0 || h.m-k < 0 || visit[h.n][h.m-k]) return;
        que[rear++] = {h.n, h.m-k, h.s, bf};
        visit[h.n][h.m-k] = 2;
    } else if(que[bf].s == 3) {
        if(h.n+k >= n || h.m >= m || h.n+k < 0 || h.m < 0 || visit[h.n+k][h.m]) return;
        que[rear++] = {h.n+k, h.m, h.s, bf};
        visit[h.n+k][h.m] = 2;
    } else if(que[bf].s == 4) {
        if(h.n-k >= n || h.m >= m || h.n-k < 0 || h.m < 0 || visit[h.n-k][h.m]) return;
        que[rear++] = {h.n-k, h.m, h.s, bf};
        visit[h.n-k][h.m] = 2;
    }
#ifdef DEBUG
    pV();
#endif
}

void bfs() {
    while (front < rear) {
        Q h = que[front];
        if(h.m == f.m && h.n == f.n && h.s == f.s) {
            for (int i = front; i > 0; i=que[i].b) {
                ans++;
            }
            return;
        }
        go(1, front);
        go(2, front);
        go(3, front);
        turn('l', front);
        turn('r', front);
        front++;
    }
}

int main() {
    setting;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> visit[i][j];
        }
    }
    cin >> s.n >> s.m >> s.s;
    cin >> f.n >> f.m >> f.s;
    que[rear++] = {s.n, s.m, s.s, -1};
    visit[s.n][s.m] = 2;
    bfs();
    cout << ans << "\n";
    return 0;
}