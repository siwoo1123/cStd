#include <iostream>
#define setting ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int n, m, r, c, s, k, visit[1010][1010], head, tail;

int dx[8] = {
        1, -1, 1, -1, 2, -2, 2, -2
}, dy[8] = {
        2, 2, -2, -2, 1, 1, -1, -1
};

struct Q {int r, c, cnt;} que[1000010];

bool isContinue(int x, int y) {
    if((x < 1 || x > n) || (y < 1 || y > m) || (visit[x][y])) return true;
    return false;
}

bool isAnwser(int x, int y) {
    if(x==s && y==k) return true;
    return false;
}

void pushQ(Q q[], Q msg) {
    if(isContinue(msg.r, msg.c)) return;
    q[tail++] = msg;
    visit[msg.r][msg.c] = 1;
}

void bfs() {
    while (true) {
        int x = que[head].r, y = que[head].c, l = que[head].cnt;
        for (int i = 0; i < 8; ++i) {
            pushQ(que, {x+dx[i], y+dy[i], l+1});
        }
        if(isAnwser(x, y)) return;
        head++;
        if(head == tail) return;
    }
}

int main() {
    setting;
    cin >> n >> m;
    cin >> r >> c >> s >> k;
    pushQ(que, {r, c, 0});
    bfs();
    cout << que[head].cnt << "\n";
    return 0;
}