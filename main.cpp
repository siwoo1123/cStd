#include <iostream>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
//#define DEBUG
using namespace std;

int n, s;
long long ans;
struct Week {
    int c, y;
} weeks[10010];

int main() {
    setting
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> weeks[i].c >> weeks[i].y;
    }
    int price = 1e9;
    for (int i = 1; i <= n; ++i) {
        price = min(weeks[i].c, price + s);
        ans += price*weeks[i].y;
    }
    cout << ans << "\n";
    return 0;
}