# ![](hd_logo.png)  Intermediate_Coder ~ 
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

* 영역 구하기
```c++
#include <iostream>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)

using namespace std;

struct Po{
    int x, y;
};

struct SagackhungPoint {
    int x1, y1, x2, y2;
} namo[120];

int arr[120][120], n, m, k, visit[120][120], voidNum, voidArr[12000000];

void dfs(Po po, int num) {
    int x = po.x, y = po.y;
    if(x < 0 || y < 0 || x >= m || y >= n || visit[x][y] || arr[x][y]) return;
    visit[x][y] = 1;
    voidArr[num]++;
    dfs({x+1, y}, num);
    dfs({x-1, y}, num);
    dfs({x, y+1}, num);
    dfs({x, y-1}, num);
}

int main(){
    setting;
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> namo[i].x1 >> namo[i].y1 >> namo[i].x2 >> namo[i].y2;
    }

    for (int i = 0; i < k; ++i) {
        for (int j = namo[i].y1; j < namo[i].y2; ++j) {
            for (int l = namo[i].x1; l < namo[i].x2; ++l) {
                arr[j][l] = 1;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(arr[i][j] == 0 && visit[i][j] == 0) {
                dfs({i, j}, voidNum++);
            }
        }
    }

    sort(voidArr, voidArr+voidNum);
    cout << voidNum << "\n";
    for (int i = 0; i < voidNum; ++i) {
        cout << voidArr[i] << " ";
    }
    cout << "\n";
    return 0;
}
```
* 치즈
```c++
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
```

* Tutorial: for문의 두번째 문법(range_based_for)
```c++
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    char arr[26];
    int point=0;

    for (int i = 65; i <= 90; ++i) {
        arr[point++] = i;
    }

    for (char ch : arr) {
        cout << ch << " ";
    }
    cout << "\n";
    return 0;
}
```

* Tutorial: STL vector1
```c++
#include <iostream>
#include <vector>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)

using namespace std;

int n;
vector<vector<int>> v;


int main(){
    setting;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;
        vector<int> ipt(len);
        for (int& x : ipt) {
            cin >> x;
        }
        v.push_back(ipt);
    }
    vector<int> sort(n);
    for (int& x : sort) {
        cin >> x;
    }
    for (int i = 0; i < n; ++i) {
        for (int x : v[sort[i]]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
```
* Tutorial: STL vector2
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)

using namespace std;

void chb(vector<int> & vector1);

bool isNotEmpty(vector<int> & arr) {
    if(arr.empty()) return false;
    return true;
}

int main() {
    setting;

    int n, x;
    char cmd;
    cin >> n >> x;
    vector<int> v(n, x);
    while (1) {
        cin >> cmd;
        if(cmd == 'i') {
            int num;
            cin >> num;
            v.push_back(num);
        } else if(cmd == 'r') {
            if(isNotEmpty(v)) {
                v.pop_back();
            }
        } else if(cmd == 's') {
            sort(v.begin(), v.end());
        } else if(cmd == 't') {
            if(isNotEmpty(v)) {
                chb(v);
            }
        } else if(cmd == 'e') break;

    }
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

void chb(vector<int> & arr) {
    int tmp = arr.front();
    arr.front() = arr.back();
    arr.back() = tmp;
}
```