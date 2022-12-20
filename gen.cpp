#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    ll a = 0, b = 1, c, x, y, r = 0;
    a = rnd() % (ll) 1e4;
    while (a == 0 && b == 0) {
        b = rnd() % (ll) 1e4;
    }
    c = rnd() % (ll) 1e4;
    x = rnd() % (ll) 1e4;
    y = rnd() % (ll) 1e4;
    while (r == 0) {
        r = rnd() % (ll) 1e4;
    }
    cout << x << " " << y << " " << r << " " << a << " " << b << " " << c;
    return 0;
}
