/*
(----------------)
 )              (
(     DNA 조합    )
 )   2021.8.5   (
(        ~       )
 )  2021.8.10   (
(                )
 )--------------(
 */
#include <iostream>
#include <string.h>
#include <algorithm>
#define null NULL

using namespace std;

int n, ans=99999999, arr[30], dnalen[30], totallen;
char dna[30][30];

bool check(int what) {
    for (int i = 0; i < n; ++i) {
        if(arr[i] == what) return false;
    }
    return true;
}

int check2(int a, int b) {
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

bool update() {
    int res = totallen;
    for (int i = 0; i < n-1; ++i) {
        res -= check2(arr[i], arr[i+1]);
    }
    ans = min(ans, res);
}

void dfs(int step) {
    if(step >= n) {
        update();
    } else {
        for (int i = 0; i < n; ++i) {
            if(check(i)) {
                arr[step] = i;
                dfs(step+1);
                arr[step] = -1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    cout.tie(null);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> dna[i];
        arr[i] = -1;
        dnalen[i] = strlen(dna[i]);
        totallen += dnalen[i];
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}
