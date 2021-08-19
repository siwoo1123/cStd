#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    char arr[26];
    int point=0;

    for (int i = 65; i <= 90; ++i) {
        arr[point++] = i;
    }

    for (char ch : arr) {
        cout << ch << " ";
    }
    cout << "\n";
    return 0;
}
