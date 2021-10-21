# ![](hd_logo.png)
* CLion return code 138 (interrupted by signal 10: SIGBUS) = Runtime Error:Segmentation fault
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
// [출처] https://github.com/siwoo1123/cStd
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
// [출처] https://github.com/siwoo1123/cStd
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
// [출처] https://github.com/siwoo1123/cStd
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
// [출처] https://github.com/siwoo1123/cStd
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
// [출처] https://github.com/siwoo1123/cStd
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
// [출처] https://github.com/siwoo1123/cStd
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
// [출처] https://github.com/siwoo1123/cStd
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
// [출처] https://github.com/siwoo1123/cStd
```
* 미로 탐색
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

int n, m;

int visit[100100];
vector<vector<int>> v;

bool isNotGo(int po) {
    return !visit[po];
}

bool isAllGo() {
    vector<int> allNum;
    for (int i = 1; i <= n; ++i) {
        allNum.push_back(i);
    }
    for (int x : allNum) {
        if(isNotGo(x)) return false;
    }
    return true;
}

void dfs(int room) {
    cout << room << " ";
    visit[room] = 1;
    for (int x : v[room]) {
        if(isNotGo(x)) {
            dfs(x);
        }
    }
}

int main() {
    setting;
    cin >> n >> m;
    v.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int ele, po;
        cin >> po >> ele;
        v[po].push_back(ele);
        v[ele].push_back(po);
    }
    for (int i = 0; i <= n; ++i) {
        sort(v[i].begin(), v[i].end());
    }

    dfs(1);

    return 0;
}
// [출처] https://github.com/siwoo1123/cStd
```
* 키순서
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

vector<vector<int>> big, small;

int sv[505], bv[505], ans, smresult[505], biresult[505];

int n, m;

void smdfs(int a, int b) {
sv[b] = 1;
smresult[a]++;
for (int x : small[b]) {
if(!sv[x]) {
smdfs(a, x);
}
}
}

void bidfs(int a, int b){
bv[b] = 1;
biresult[a]++;
for (int x : big[b]) {
if(!bv[x]) {
bidfs(a, x);
}
}
}

int main(){
setting;
cin >> n >> m;
big.resize(n+2);
small.resize(n+2);
for (int i = 0; i < m; ++i) {
int a, b;
cin >> a >> b;
small[b].push_back(a);
big[a].push_back(b);
}

for (int i = 1; i <= n; ++i) {
for (int j = 1; j <= n; ++j) {
sv[j] = bv[j] = 0;
}
smdfs(i, i);
bidfs(i, i);
}

for (int i = 1; i <= n; ++i) {
if(((smresult[i] + biresult[i]) - 1) == n) ans++;
}

cout << ans << "\n";

return 0;
}
// [출처] https://github.com/siwoo1123/cStd
```
* 등수찾기
```c++
#include <iostream>
#include <vector>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

vector<vector<int>> big, small;
int n, m, x, bv[100005], sv[100005], smresult[100005], biresult[100005];

void smdfs(int a, int b) {
    sv[b] = 1;
    smresult[a]++;
    for (int y : small[b]) {
        if(!sv[y]) {
            smdfs(a, y);
        }
    }
}

void bidfs(int a, int b){
    bv[b] = 1;
    biresult[a]++;
    for (int y : big[b]) {
        if(!bv[y]) {
            bidfs(a, y);
        }
    }
}

int main() {
    setting;
    cin >> n >> m >> x;
    big.resize(n+2); small.resize(n+2);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        big[b].push_back(a);
        small[a].push_back(b);
    }

    smdfs(x,x);
    bidfs(x,x);

    cout << biresult[x] << " " << n-smresult[x]+1 << "\n";

    return 0;
}
// [출처] https://github.com/siwoo1123/cStd
```
* 두 로봇
```c++
#include <iostream>
#include <vector>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;
struct Data {int po, dis;};
int n, r1, r2, visit[100010];
vector<vector<Data>> map(100010);

void dfs(int po, int sum, int big) {
    if(po == r2) {
        cout << sum - big << "\n";
        return;
    }
    visit[po] = 1;

    for (Data x : map[po]) {
        if(visit[x.po]) continue;
        if(big < x.dis) dfs(x.po, sum+x.dis, x.dis);
        else dfs(x.po, sum+x.dis, big);
    }
}

int main() {
    setting;
    cin >> n >> r1 >> r2;
    for (int i = 1; i <= n-1; ++i) {
        int a, b, p;
        cin >> a >> b >> p;
        map[a].push_back({b, p});
        map[b].push_back({a, p});
    }

    dfs(r1, 0, 0);

}
// [출처] https://github.com/siwoo1123/cStd
```
> 그래프탐색-BFS
* 장기2
```c++
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
// [출처] https://github.com/siwoo1123/cStd
```
* 저글링 방사능 오염
```c++
#include <iostream>
#include <stdio.h>
#define setting ios_base :: sync_with_stdio(false);cout.tie(NULL)
using namespace std;

int ipt[110][110];
int x, y, visit[110][110], dX, dY, head, tail;
int mx[4] = {0, 0, -1, 1}, my[4] = {-1, 1, 0, 0};

struct Que{
    int x, y, pack;
} que[10010];

bool Ok(int xf, int yf) {
    if(visit[xf][yf] == 1) return false;
    if(xf <= 0 || yf <= 0 || xf > x || yf > y) return false;
    return true;
}

void push(Que ipts) {
    if(Ok(ipts.x, ipts.y)) {
        que[tail++] = ipts;
        visit[ipts.x][ipts.y] = 1;
    }
}

void bfs() {
    while (1) {
        for (int i = 0; i < 4; ++i) {
            int nx = que[head].x + mx[i], ny = que[head].y + my[i];
            if((nx <= 0 || ny <= 0 || nx > x || ny > y) || ipt[nx][ny] == 0 || visit[nx][ny]) continue;
            push({nx, ny, que[head].pack+1});
        }
        head++;
        if(head == tail) break;
    }
    cout << que[head-1].pack << "\n";
}

int main() {
    setting;
    scanf("%d %d", &y, &x);
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            scanf("%1d", &ipt[i][j]);
        }
    }
    scanf("%d %d", &dY, &dX);

    push({dX, dY, 3});
    bfs();
    int a=0;
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            if(visit[i][j] == 0 && ipt[i][j] == 1) a++;
        }
    }
    cout << a << "\n";
    return 0;
}
// [출처] https://github.com/siwoo1123/cStd
```
* 보물섬
```c++
#include <stdio.h>
#include <memory.h>
using namespace std;

char board[55][55];
int n, m, ans;
struct Que {
    int r, c;
    int cnt;
} que[55*55];
int front, rear;
int visit[55][55];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void push(Que ipt) {
    if(visit[ipt.r][ipt.c] || board[ipt.r][ipt.c] != 'L') return;
    visit[ipt.r][ipt.c] = 1;
    que[rear++] = ipt;
}

int bfs(int r, int c){
    memset(visit, 0, sizeof(visit));
    front = rear = 0;
    push({r, c, 0});
    while(front < rear) {
        Que now = que[front++];
        for (int i = 0; i < 4; ++i) {
            push({ now.r + dr[i], now.c + dc[i], now.cnt + 1 });
        }
    }
    return que[front-1].cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", board[i]+1);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(board[i][j] == 'L') {
                int dist = bfs(i, j);
                if(ans < dist) ans = dist;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
// [출처] https://github.com/siwoo1123/cStd
```
* 토마토(고)(코드업: 토마토(고등))
```c++
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
// [출처] https://github.com/siwoo1123/cStd
```
* 화염에서 탈출
```c++
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
    if(pq.r < 0 || pq.c < 0 || pq.r >= r || pq.c >= c || visit[pq.r][pq.c] == 1 || (pq.fireOrPlayer == 'fin' && visit[pq.r][pq.c] == 2)) return;
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
                push({i, j, 0, 'fin'});
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
// [출처] https://github.com/siwoo1123/cStd
```
* 경로 찾기
```c++
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
// [출처] https://github.com/siwoo1123/cStd
```
* 소수와 함깨하는 여행
```c++
#include <iostream>
#include <math.h>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

int sosu[10011], ss, fs, front, rear, ans, visit[10010];
struct Q {
    int b, h;
} que[10010];

void Eratos()
{
    sosu[0]=sosu[1]=1;
    for (int i = 2; i <= 100; ++i) {
        if(sosu[i]==0) {
            for (int j = i*i; j <= 10000; j+=i) {
                sosu[j]=1;
            }
        }
    }
}

void push(Q q) {
    if(visit[q.h] || sosu[q.h]) return;
    que[rear++] = q;
    visit[q.h] = 1;
}

void bfs() {
    push({-1, ss});
    while (front < rear) {
        Q h = que[front];
        if(h.h == fs) {
            for (int i = front; i > 0; i=que[i].b) {
                ans++;
            }
            return;
        }
        int o = h.h % 10;
        int t = (h.h % 100) / 10;
        int T = (h.h / 100) % 10;
        int f = h.h / 1000;
        for (int i = 1; i <= 9; ++i) {
            if(o + i <= 9) {
                push({front, (f*1000)+(T*100)+(t*10)+(o+i)});
            }
            if(t + i <= 9) {
                push({front, (f*1000)+(T*100)+((t+i)*10)+o});
            }
            if(T + i <= 9) {
                push({front, (f*1000)+((T+i)*100)+(t*10)+o});
            }
            if(f + i <= 9) {
                push({front, ((f+i)*1000)+(T*100)+(t*10)+o});
            }
            if(o - i >= 0) {
                push({front, (f*1000)+(T*100)+(t*10)+(o-i)});
            }
            if(t - i >= 0) {
                push({front, (f*1000)+(T*100)+((t-i)*10)+o});
            }
            if(T - i >= 0) {
                push({front, (f*1000)+((T-i)*100)+(t*10)+o});
            }
            if(f - i > 9) {
                push({front, ((f-i)*1000)+(T*100)+(t*10)+o});
            }
        }
        front++;
    }
}

int main() {
    setting;
    Eratos();
    cin >> ss >> fs;
    if(ss > fs) {
        int tmp = ss;
        ss = fs;
        fs = tmp;
    }
    bfs();
    cout << ans << "\n";
    return 0;
}
// [출처] https://github.com/siwoo1123/cStd
```
* 로봇
```c++
#include <iostream>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

int n, m, front, rear, visit[110][110][5];
int ipt[110][110];
struct {int n, m, s;} s, f;
struct Q {
    int n, m, s, b;
} que[50000];

int dn[5] = { 0, 0, 0, 1, -1 };
int dm[5] = { 0, 1, -1, 0, 0 };

void push(Q i) {
    if(visit[i.n][i.m][i.s]) return;
    visit[i.n][i.m][i.s] = 1;
    que[rear++] = i;
}

int bfs() {
    push({s.n, s.m, s.s, 0});
    while(front < rear) {
        Q h = que[front++];
        if(h.n == f.n && h.m == f.m && h.s == f.s) return h.b;
        if(h.s < 3) {
            push({h.n, h.m, 4, h.b+1});
            push({h.n, h.m, 3, h.b+1});
        } else {
            push({h.n, h.m, 2, h.b+1});
            push({h.n, h.m, 1, h.b+1});
        }
        int nn = h.n, nm = h.m;
        for (int i = 1; i <= 3; ++i) {
            nn += dn[h.s], nm += dm[h.s];
            if(nn <= 0 || nm <= 0 || nn > n || nm > m || ipt[nn][nm]) break;
            push({nn, nm, h.s, h.b+1});
        }
    }
    return 0;
}

int main() {
    setting;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> ipt[i][j];
        }
    }
    cin >> s.n >> s.m >> s.s;
    cin >> f.n >> f.m >> f.s;

    cout << bfs() << "\n";
    return 0;
}
// [출처] https://github.com/siwoo1123/cStd
```
* 버스 갈아타기
![](2578(버스갈아타기)-JungOl.png)
```c++
#include <iostream>
#include <vector>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;
 
int n, m, k;
vector<int> fb;
struct Pos {int x, y;};
struct Bus {
    Pos s, c;
} buses[5010];
struct Q {
    int bus, cnt;
} que[5010];
int front, rear, visit[5010];
 
bool canTransform(int a, int b) {
    if (buses[a].c.x < buses[b].s.x) {
        return false;
    }
    if (buses[b].c.x < buses[a].s.x) {
        return false;
    }
    if (buses[a].c.y < buses[b].s.y) {
        return false;
    }
    if (buses[b].c.y < buses[a].s.y) {
        return false;
    }
    return true;
}
 
bool isAnswer(Q h) {
 
    return false;
}
 
void push(Q ipt) {
    if(visit[ipt.bus]) return;
    que[rear++] = ipt;
    visit[ipt.bus] = 1;
}
 
void bfs() {
    push({0, 0});
    while (front < rear) {
        Q h = que[front++];
        for (int x : fb) {
            if(h.bus == x) {
                cout << h.cnt << "\n";
                return;
            }
        }
        for (int i = 1; i <= k; ++i) {
            if(canTransform(h.bus, i)) {
                push({i, h.cnt+1});
            }
        }
    }
}
 
int main() {
    setting;
    cin >> m >> n >> k;
    for (int i = 1; i <= k; ++i) {
        int tmp = 0;
        cin >> tmp;
        cin >> buses[tmp].s.x >> buses[tmp].s.y >> buses[tmp].c.x >> buses[tmp].c.y;
        if((buses[tmp].s.x > buses[tmp].c.x) || (buses[tmp].s.y > buses[tmp].c.y)){
            Pos immsi = buses[tmp].s;
            buses[tmp].s = buses[tmp].c;
            buses[tmp].c = immsi;
        }
    }
    Pos s, f;
    cin >> s.x >> s.y >> f.x >> f.y;
    buses[0].s = {s.x, s.y};
    buses[0].c = {s.x, s.y};
    for (int i = 1; i <= k; ++i) {
        if(buses[i].s.y == buses[i].c.y) {
            for (int j = buses[i].s.x; j <= buses[i].c.x; ++j) {
                if(f.x == j && f.y == buses[i].s.y) {
                    fb.push_back(i);
                    break;
                }
            }
        } else {
            for (int j = buses[i].s.y; j <= buses[i].c.y; ++j) {
                if(f.y == j && f.x == buses[i].s.x) {
                    fb.push_back(i);
                    break;
                }
            }
        }
    }
    bfs();
    return 0;
}
// [출처] https://github.com/siwoo1123/cStd
```