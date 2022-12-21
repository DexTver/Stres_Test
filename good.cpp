#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
vector<ll> a;
vector<ll> tree;
ll sz = 1;

void combine(ll x, ll x1, ll x2, ll lx, ll rx) {
    tree[x] = tree[x1] + tree[x2];
}


void build(vector<ll>& a, ll x, ll lx, ll rx) {
    if (rx - lx == 1) {
        if (lx < (ll)a.size() && a[lx] == 0) {
            tree[x] = 1;
        }
        else {
            tree[x] = 0;
        }
        return;
    }
    ll m = (lx + rx) / 2;
    build(a, x * 2 + 1, lx, m);
    build(a, x * 2 + 2, m, rx);
    combine(x, x * 2 + 1, x * 2 + 2, lx, rx);
}

void upd(ll ind, ll x, ll lx, ll rx) {
    if (rx - lx == 1) {
        if (a[lx] == 0) tree[x] = 1;
        else
            tree[x] = 0;
        return;
    }
    ll m = (lx + rx) / 2;
    if (ind < m)upd(ind, x * 2 + 1, lx, m);
    else
        upd(ind, x * 2 + 2, m, rx);
    combine(x, x * 2 + 1, x * 2 + 2, lx, rx);
}

ll qry(ll k, ll x, ll lx, ll rx) {
    if (tree[x] < k) return -1;
    if (rx - lx == 1) return lx + 1;
    ll m = (lx + rx) / 2;
    if (k <= tree[x * 2 + 1]) return qry(k, x * 2 + 1, lx, m);
    else
        return qry(k - tree[x * 2 + 1], x * 2 + 2, m, rx);
}

ll sum(ll l, ll r, ll x, ll lx, ll rx) {
    if (l >= rx || r <= lx) return 0;
    if (l <= lx && rx <= r) return tree[x];
    ll m = (lx + rx) / 2;
    return sum(l, r, x * 2 + 1, lx, m) + sum(l, r, x * 2 + 2, m, rx);
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    ll n;
    cin >> n;
    while (sz < n) sz *= 2;
    tree.assign(sz * 2 - 1, 0);
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    build(a, 0, 0, sz);
    ll q;
    cin >> q;
    while (q--) {
        char op;
        cin >> op;
        if (op == 's') {
            ll l, r, k;
            cin >> l >> r >> k;
            k += sum(0, l - 1, 0, 0, sz);
            ll res = qry(k, 0, 0, sz);
            cout << (res <= r ? res : -1) << ' ';
        }
        else {
            ll ind, v;
            cin >> ind >> v;
            a[ind - 1] = v;
            upd(ind - 1, 0, 0, sz);
        }
    }
}