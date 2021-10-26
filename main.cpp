#include <iostream>
#include <algorithm>
#include <vector>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

int m, s, c, livedCowPo[210];
vector<int> gangok;

int main() {
    setting;
    cin >> m >> s >> c;
    for (int i = 0; i < c; ++i) {
        cin >> livedCowPo[i];
    }
    if(m > c) {
        m = c;
    }
    sort(livedCowPo, livedCowPo+c);
    for (int i = c-1; i > 0; --i) {
        gangok.push_back(livedCowPo[i] - livedCowPo[i-1]);
    }
    s = livedCowPo[c-1] - livedCowPo[0] + 1;
    sort(gangok.begin(), gangok.end());
    reverse(gangok.begin(), gangok.end());
    for (int i = 0; i < m-1; ++i) {
        s -= gangok[i] - 1;
    }
    cout << s << "\n";
    return 0;
}

// [출처] https://github.com/siwoo1123/cStd