#include <stdio.h>
#define DEBUGG
using namespace std;

struct Que {
  int r, c, cnt;
  char fireOrPlayer;
} que[3027];
struct {int r, c;} D;
int visit[55][55], r, c, ans = -1;
int front, rear;
char ipt[55][55];
int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, 1, 0, -1};

void OV() {
    printf("=======================\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(visit[i][j] == 0) {
                printf("  ");
                continue;
            }
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
    printf("=======================\n");
}

void push(Que pq) {
    if(pq.r < 0 || pq.c < 0 || pq.r >= r || pq.c >= c || visit[pq.r][pq.c] == 1 || (pq.fireOrPlayer == 'f' && visit[pq.r][pq.c] == 2)) return;
    if(visit[pq.r][pq.c] == 2) ans = pq.cnt;
    visit[pq.r][pq.c]=1;
    que[rear++] = pq;
}

int bfs() {
    while (front < rear) {
        Que h = que[front++];
        for (int i = 0; i < 4; ++i) {
            push({h.r+dr[i], h.c+dc[i], h.cnt+1, h.fireOrPlayer});
        }
    }
    return ans;
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) {
        scanf("%s", ipt[i]);
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(ipt[i][j] == '*') {
                push({i, j, 0, 'f'});
            } else if(ipt[i][j] == 'X') {
                visit[i][j] = 1;
            } else if(ipt[i][j] == 'D') {
                visit[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(ipt[i][j] == 'S') {
                push({i, j, 0, 'p'});
            }
        }
    }

    int result = bfs();
    if(result == -1) {
        printf("impossible\n");
    } else {
        printf("%d\n", result);
    }
    return 0;
}