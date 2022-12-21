#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//    a = rnd() % (ll) 1e4;
    int n = 10, m = 30;
    vector<int> a = {0, 1, 5, 0, 3, 67, 0, 2, 4, 0};
    cout << n << "\n";
    for (int i : a) {
        cout << i << " ";
    }
    cout << "\n" << m << "\n";
    for (int i = 0 ; i < m / 2 ; ++i) {
        cout << "u" << " " << rnd() % n + 1 << " " << rnd() % 15 << "\n";
    }
    for (int i = 0 ; i < m / 2 ; ++i) {
        cout << "s" << " " << rnd() % n + 1 << " " << rnd() % n + 1 << " " << rnd() % (n / 3 * 2) << "\n";
    }
    return 0;
}
