#include "bits/stdc++.h"
using namespace std;

#define vec vector

inline int lg(int x) {
    return __bit_width(x) - 1;
}

template<typename T>
struct SparseTable {
    vec<vec<T>> st;

    SparseTable(const vec<T>& a) {
        int n = a.size();
        int K = lg(n);

        st.assign(K + 1, vec<T>(n));
        st[0] = a;

        for (int j = 0; j < K; ++j)
            for (int i = 0; i + (2 << j) <= n; ++i)
                st[j + 1][i] = min(
                    st[j][i],
                    st[j][i + (1 << j)]
                );
    }
    
    // [l, r)
    T query(int l, int r) const {
        int j = lg(r - l);
        return min(
            st[j][l],
            st[j][r - (1 << j)]
        );
    }
};