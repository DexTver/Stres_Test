#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x0, y0, r, a, b, c;
    cin >> x0 >> y0 >> r >> a >> b >> c;
    if (a != 0) {
        ll d = (b * c + b * x0 * a - y0 * a * a) * (b * c + b * x0 * a - y0 * a * a) - (b * b + a * a)
            * (-(r * r - y0 * y0 * a * a - a * a * x0 * x0 - 2 * x0 * c * a - c * c));
        if (d < 0) {
            cout << 0;
            return 0;
        }
        if (d == 0) {
            ld y1 = (ld)(-b * c - b * x0 * a + y0 * a * a) / (ld)(b * b + a * a);
            ld x1 = (ld)(-b * y1 - c) / (ld)a;
            cout << 1 << '\n';
            cout << setprecision(20) << x1 << " " << y1;
            return 0;
        }
        ld y1 = ((ld)(-b * c - b * x0 * a + y0 * a * a) + sqrtl(d)) / (ld)(b * b + a * a);
        ld y2 = ((ld)(-b * c - b * x0 * a + y0 * a * a) - sqrtl(d)) / (ld)(b * b + a * a);
        ld x1 = (ld)(-b * y1 - c) / (ld)a;
        ld x2 = (ld)(-b * y2 - c) / (ld)a;
        cout << 2 << '\n';
        cout << setprecision(20) << x1 << " " << y1 << "\n" << x2 << " " << y2;
    }
    else {
        ll d = (a * c + b * y0 * a - x0 * b * b) * (a * c + b * y0 * a - x0 * b * b) - (b * b + a * a)
            * (-(r * r - y0 * y0 * b * b - b * b * x0 * x0 - 2 * y0 * c * b - c * c));
        if (d < 0) {
            cout << 0;
            return 0;
        }
        if (d == 0) {
            ld x1 = (ld)(-a * c - b * y0 * a + x0 * b * b) / (ld)(b * b + a * a);
            ld y1 = (ld)(-a * x1 - c) / (ld)b;
            cout << 1 << '\n';
            cout << setprecision(20) << x1 << " " << y1;
            return 0;
        }
        ld x1 = ((ld)(-a * c - b * y0 * a + x0 * b * b) + sqrtl(d)) / (ld)(b * b + a * a);
        ld x2 = ((ld)(-a * c - b * y0 * a + x0 * b * b) - sqrtl(d)) / (ld)(b * b + a * a);
        ld y1 = (ld)(-a * x1 - c) / (ld)b;
        ld y2 = (ld)(-a * x2 - c) / (ld)b;
        cout << 2 << '\n';
        cout << setprecision(20) << x1 << " " << y1 << "\n" << x2 << " " << y2;
    }
}