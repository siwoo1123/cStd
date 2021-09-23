#include <stdio.h>
using namespace std;

int tomatos[1010][1010];
int n, m;
struct Que {
    int r, c;
    int cnt;
} que[1010*1010];
int front, rear;
int visit[1010][1010];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


void push(Que ipt) {
    if(visit[ipt.r][ipt.c] || ipt.r < 0 || ipt.c < 0 || ipt.r >= n || ipt.c >= m || tomatos[ipt.r][ipt.c] == -1) return;
    visit[ipt.r][ipt.c] = 1;
    que[rear++] = ipt;
}

int bfs(){
    while(front < rear) {
        Que h = que[front];
        for (int i = 0; i < 4; ++i) {
            push({h.r+dr[i], h.c+dc[i], h.cnt+1});
        }
        front++;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(visit[i][j]==0&&tomatos[i][j]==0) return -1;
        }
    }
    return que[front - 1].cnt;
}

int main () {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &tomatos[i][j]);
            if(tomatos[i][j]==1) {
                push({i, j, 0});
            }
        }
    }

    printf("%d\n", bfs());

    return 0;
}