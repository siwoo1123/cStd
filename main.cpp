#include <iostream>
#include <string>
#include <algorithm>
#define setting ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
//#define DEBUG
using namespace std;

struct Yak {
    int id, x, y;
    bool operator<(const Yak &r)const
    {
        if(y==r.y) return x<r.x;
        return y<r.y;
    }
} yaks[510];

int n, ans=1;

struct DebugTools {
    void printYak() {
#ifdef DEBUG
        cout << "========== 약 ==========\n";
        for (int i = 1; i <= n; ++i) {
            cout << "id: " << yaks[i].id << " 최저온도: " << yaks[i].x << "°C 최고온도: " << yaks[i].y << "°C\n";
        }
        cout << "========================\n";
#endif
    }
    void print(string a) {
#ifdef DEBUG
        cout << a;
#endif
    }
    void println(string a) {
#ifdef DEBUG
        cout << a+"\n";
#endif
    }
} debugTool;

int main() {
    setting
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> yaks[i].x >> yaks[i].y;
        yaks[i].id = i;
    }
    debugTool.println("정렬 전");
    debugTool.printYak();
    debugTool.println("정렬 후");
    sort(yaks+1, yaks+(n+1));
    debugTool.printYak();


    int temp = yaks[1].y;
    debugTool.println(to_string(temp));
    debugTool.println("");
    for (int i = 1; i <= n; ++i) {
        if(temp < yaks[i].x) {
            debugTool.print("ans++전 ans: ");
            debugTool.println(to_string(ans));
            ans++;
            debugTool.print("temp: ");
            temp = yaks[i].y;
            debugTool.println(to_string(temp));
            debugTool.print("ans++후 ans: ");
            debugTool.println(to_string(ans));
            debugTool.println("");
        }
    }
    debugTool.println("");
    cout << ans << "\n";
    return 0;
}