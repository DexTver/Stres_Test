#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector<int> a, t;

    SegmentTree(const vector<int> &data) {
        a = data;
        t.resize(4 * a.size());
        build(0, 0, (int) a.size());
    }

    void build(int v, int l, int r) {
        if (l + 1 == r) {
            t[v] = a[l] == 0 ? 1 : 0;
            return;
        }
        int m = (l + r) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void change(int v, int l, int r, int pos, int newVal) {
        if (l + 1 == r) {
            t[v] = newVal == 0 ? 1 : 0;
            return;
        }
        int m = (l + r) / 2;
        if (pos < m) {
            change(2 * v + 1, l, m, pos, newVal);
        } else {
            change(2 * v + 2, m, r, pos, newVal);
        }
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    int get(int v, int l, int r, int k) {
        if (l + 1 == r) {
            return l;
        }
        int m = (l + r) / 2;
        if (t[2 * v + 1] >= k) {
            return get(2 * v + 1, l, m, k);
        } else {
            return get(2 * v + 2, m, r, k - t[2 * v + 1]);
        }
    }

    pair<int, int> find(int v, int l, int r, int k, int ql, int qr) {
        if (r <= ql || qr <= l) {
            return {-2, 0};
        }
        if (ql <= l && r <= qr) {
            if (t[v] < k) {
                return {-2, t[v]};
            }
            return {get(v, l, r, k), t[v]};
        }
        int m = (l + r) / 2;
        pair<int, int> res = find(v * 2 + 1, l, m, k, ql, qr);
        if (res.first != -2) {
            return res;
        }
        return find(v * 2 + 2, m, r, k - res.second, ql, qr);
    }
};

int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, ind, newVal, l, r, k;
    cin >> n;
    vector<int> data(n);
    for (int i = 0 ; i < n ; ++i) {
        cin >> data[i];
    }
    SegmentTree tree = SegmentTree(data);

    cin >> m;
    char com;
    while (m--) {
        cin >> com;
        if (com == 's') {
            cin >> l >> r >> k;
            cout << tree.find(0, 0, n, k, l - 1, r).first + 1 << " ";
        } else {
            cin >> ind >> newVal;
            tree.change(0, 0, n, ind - 1, newVal);
        }
    }
    return 0;
}
