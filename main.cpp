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
