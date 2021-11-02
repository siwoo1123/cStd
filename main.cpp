#include <iostream>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
using namespace std;

struct Meeting {
    int id, start, end;
    bool operator<(const Meeting &r)const
    {
        return end<r.end;
    }
} meeting[510];
int n;

int main() {
    setting;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int mtid;
        cin >> mtid;
        meeting[mtid].id = mtid;
        cin >> meeting[mtid].start;
        cin >> meeting[mtid].end;
    }
    sort(meeting+1, meeting+n+1);
    for (int i = 1; i <= n; ++i) {
        cout << meeting[i].id << " ";
        cout << meeting[i].start << " ";
        cout << meeting[i].end << "\n";
    }
}