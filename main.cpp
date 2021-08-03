      //--------------------------------//
     //                                //
    //    2021.7.29 Thu ~ 2021.8.03   //
   //               비숍              //
  //           jungol.co.kr         //
 //                                //
//--------------------------------//
#include <iostream>
#define nil NULL
using namespace std;

int bishop[15][15], n, cnt;

int dfs(int step){
    if(step >= (n*2)-1){
        return 1;
    }

    int x, y;
    if(step <= n-1) {
        x = step, y = 0;
        for (int i = 0; i < n; ++i) {
            if(bishop[step][i] == 0) continue;
            bishop[x--][y++] = 0;
            cnt++;
            if(dfs(step+1) == 1) return 1;
            cnt--;
            bishop[x+1][y-1] = 1;
        }
    } else {
        x=n-1;
        y = step+1-n;
        for (int i = 0; i < n; ++i) {
            if(bishop[step][i] == 0) continue;
            bishop[x++][y--] = 0;
            cnt++;
            if(dfs(step+1) == 1) return 1;
            cnt--;
            bishop[x-1][y+1] = 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nil);
    cout.tie(nil);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> bishop[i][j];
        }
    }
    dfs(0);
    cout << cnt << "\n";
    return 0;
}
