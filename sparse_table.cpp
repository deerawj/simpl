#include "bits/stdc++.h"
using namespace std;

inline int lg(int x) {
    return __bit_width(x) - 1;
}

struct SparseTable {
    vector<vector<int>> st;

    SparseTable(const vector<int>& a) {
        int n = a.size();
        int K = lg(n);

        st.assign(K + 1, vector<int>(n));
        st[0] = a;

        for (int j = 0; j < K; ++j)
            for (int i = 0; i + (2 << j) <= n; ++i)
                st[j + 1][i] = min(
                    st[j][i],
                    st[j][i + (1 << j)]
                );
    }
    
    // [l, r)
    int query(int l, int r) const {
        int j = lg(r - l);
        return min(
            st[j][l],
            st[j][r - (1 << j)]
        );
    }
};