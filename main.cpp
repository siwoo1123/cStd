/*
(----------------)
 )              (
(     DNA 조합    )
 )   2021.8.5   (
(        ~       )
 )   2021.8.5   (
(                )
 )--------------(
 */
#include <iostream>
#define null NULL

using namespace std;

int n, ans=99999999, visit[21];
char dna[21][21];


void dfs(int step, int cnt) {
    if(step >= n) {
        if(ans > cnt) ans = cnt;
        return;
    }

    for (int i = 0; i < n; ++i) {
        visit[i] = 1;
        dfs(step+1, cnt);
        visit[i]=0;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    cout.tie(null);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> dna[i];
    }

    dfs(0, 0);
    return 0;
    //Win7 CRUD BOARD!
}