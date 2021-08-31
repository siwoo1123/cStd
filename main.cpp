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
