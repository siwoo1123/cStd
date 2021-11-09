#include <iostream>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;
//  1  5  10  50 100  500
int a, b, c, d, e, f, n;
int result[7] = {
        //  1  5  10  50 100 500
        0, 0, 0, 0, 0, 0, 0
};

int main() {
    setting;
    cin >> n;
    cin >> f >> e >> d >> c >> b >> a;
    int ipt[7] = {
            0, f, e, d, c, b, a
    };
    n = (a+b*5+c*10+d*50+e*100+f*500) - n;
    for (int i = 1; i <= f; ++i) {
        if((n)/500 > 0) {
            n-=500;
            result[6]++;
        } else break;
    }
    for (int i = 1; i <= e; ++i) {
        if((n)/100 > 0) {
            n-=100;
            result[5]++;
        } else break;
    }
    for (int i = 1; i <= d; ++i) {
        if((n)/50 > 0) {
            n-=50;
            result[4]++;
        } else break;
    }
    for (int i = 1; i <= c; ++i) {
        if((n)/10 > 0) {
            n-=10;
            result[3]++;
        } else break;
    }
    for (int i = 1; i <= b; ++i) {
        if((n)/5 > 0) {
            n-=5;
            result[2]++;
        } else break;
    }
    for (int i = 1; i <= a; ++i) {
        if((n)/1 > 0) {
            n-=1;
            result[1]++;
        } else break;
    }
    int ans = 0;
    reverse(result+1, result+7);
    for (int i = 0; i < 7; ++i) {
        result[i] = ipt[i] - result[i];
    }
    for (int i = 1; i < 7; ++i) {
        ans += result[i];
    }
    cout << ans << "\n";
    for (int i = 1; i < 7; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}