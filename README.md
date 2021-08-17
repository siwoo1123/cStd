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
```

>그래프탐색-DFS

* 단지번호 붙이기
```c++
#include <iostream>
#include <algorithm>

using namespace std;

struct Pos {
int x, y;
};

int n, danjee, danjeeArr[30000], visit[30][30];
char arr[30][30];

int charToInt(char ch) {
return ch - 48;
}

void dfs(Pos pos, int num) {
int x = pos.x, y = pos.y;
if(x < 0 || y < 0 || x >= n || y >= n || charToInt(arr[x][y]) == 0 || visit[x][y]) return;
danjeeArr[num]++;
visit[x][y] = 1;
dfs({x, y+1}, num);
dfs({x, y-1}, num);
dfs({x+1, y}, num);
dfs({x-1, y}, num);
}

int main() {
cin >> n;
for (int i = 0; i < n; ++i) {
cin >> arr[i];
}

for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
if(charToInt(arr[i][j]) == 1 && visit[i][j] == 0) {
dfs({i, j}, ++danjee);
}
}
}
sort(danjeeArr+1, danjeeArr+danjee+1);
cout << danjee << "\n";
for (int i = 1; i <= danjee; ++i) {
cout << danjeeArr[i] << "\n";
}

return 0;
}

```