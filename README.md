# C++ project
>백트래킹-DFS
* DNA조합
```c++

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, ans=999, arr[30], visit[30], dnalen[30], totallen;
char dna[30][30];

int check(int a, int b) {
  for(int i=min(dnalen[a], dnalen[b]); i>0; i--){
    int flag = 1;
    for(int j=0; j<i; j++){
      if(dna[a][dnalen[a]-i+j] != dna[b][j]){
        flag = 0;
        break;
      }
    }
    if(flag){
      return i;
    }
  }
  return 0;
}

void update() {
  int res = totallen;
  for (int i = 0; i < n-1; ++i) {
    res -= check(arr[i], arr[i+1]);
  }
  ans = min(ans, res);
}

void dfs(int step) {
  if(step >= n) {
    update();
  } else {
    for (int i = 0; i < n; ++i) {
      if(!visit[i]) {
        arr[step] = i;
        visit[i] = 1;
        dfs(step+1);
        visit[i] = 0;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", dna[i]);
    dnalen[i] = strlen(dna[i]);
    totallen += dnalen[i];
  }
  dfs(0);
  printf("%d\n", ans);
  return 0;
}
```
* 장기
```c++
#include <iostream>

using namespace std;

int n, m, r, c, s, k, janggi[110][110], ans;

int dx[9] = {
1, -1, 1, -1, 2, -2, 2, -2
}, dy[9] = {
2, 2, -2, -2, 1, 1, -1, -1
};


void update_cell(int x, int y, int diff) {
if(x < 0 || n <= x) return;
if(y < 0 || m <= y) return;
if(janggi[x][y] == -1) janggi[x][y] = diff;
}
int update(int step) {
int flag = 0;
for (int i = 0; i < n; ++i) {
for (int j = 0; j < m; ++j) {
if(janggi[i][j] == step){
flag = 1;
for (int k = 0; k < 8; ++k) {
update_cell(i+dx[k], j+dy[k], step+1);
}
}
}
}
return flag;
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

janggi[r-1][c-1] = 0;
int flag = 1;
for(int i=0; flag; i++){
flag = update(i);
}
// OUTPUT
cout << janggi[s-1][k-1]  << "\n";

//RETURN
return 0;
}
```