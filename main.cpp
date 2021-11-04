#include <iostream>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

int n, ch[1010];

int main() {
    setting
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ch[i];
    }
    sort(ch, ch+n);
    if(ch[0] != 1) {
        cout << "1\n";
        return 0;
    }
    int sum = ch[0];
    for (int i = 1; i < n; ++i) {
        if(sum+1 < ch[i]) break;
        sum += ch[i];
    }
    cout << sum+1 << "\n";
    return 0;
}