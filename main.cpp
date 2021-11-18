#include <iostream>
#include <algorithm>
#include <vector>
#define INPUT_OUTPUT_SETTING ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

struct Flower{
    int pinunnal, jinunnal;
    bool operator<(const Flower &r) const {
        if(pinunnal == r.pinunnal) {
            return jinunnal < r.jinunnal;
        }
        return pinunnal < r.pinunnal;
    }
} flower[100010];

int DateToInt(int month, int day) {
    return (month*100) + day;
}

int n, ans;

int main() {
    INPUT_OUTPUT_SETTING
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int month, day, a = 0;
        cin >> month >> day;
        flower[i].pinunnal = DateToInt(month, day);
        cin >> month >> day;
        flower[i].jinunnal = DateToInt(month, day);
    }
    //sort(flower, flower+n);
    int giJunJom = 301;
    int gguctNaNunJom;
    while (true) {
        gguctNaNunJom = 0;
        for (int i = 0; i < n; ++i) {
            if(flower[i].pinunnal <= giJunJom && giJunJom < flower[i].jinunnal) {
                if(flower[i].jinunnal > gguctNaNunJom) gguctNaNunJom = flower[i].jinunnal;
            }
        }
        giJunJom=gguctNaNunJom;
        ans++;
        if(giJunJom == 0) {
            cout << "0" << "\n";
            return 0;
        }
        if(giJunJom > 1130) break;
    }
    cout << ans << "\n";
}