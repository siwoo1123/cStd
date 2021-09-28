#include <iostream>
#include <vector>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

int n, k;
char ipt[1010][35];
int a, b;
struct Q {
    int h, ah;
} que[1010];
int head, tail, visit[1010];

void push(Q q) {
    if(visit[q.h]) return;
    if(q.ah >= 0) {
        int dif = 0;
        for (int i = 0; i < k; ++i) {
            if (ipt[q.h][i] != ipt[que[q.ah].h][i]) dif++;
        }
        if(dif != 1) return;
    }

    que[tail++] = q;
    visit[q.h] = 1;
}

void bfs() {
    push({a, -1});
    while (head < tail) {
        Q h = que[head++];
        if(h.h == b) {
            vector<int> ans;
            for (int i = head-1; i >= 0; i=que[i].ah) {
                ans.push_back(que[i].h);
            }
            reverse(ans.begin(), ans.end());
            for (int x : ans) {
                cout << x << " ";
            }
            cout << "\n";
            return;
        }
        for (int i = 1; i <= n; ++i) {
            push({i, head-1});
        }
    }
    cout << "-1\n";
}

int main(){
    setting;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> ipt[i];
    }
    cin >> a >> b;

    bfs();

    return 0;
}
