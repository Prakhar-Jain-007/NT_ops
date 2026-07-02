#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, k, q;
    cin>>a>>b>>k>>q;

    vector<long long> cycle = {a, b};
    vector<long long> ps = {a, a+b};
    while (true) {
        long long two = cycle[cycle.size()-2];
        long long one = cycle[cycle.size()-1];
        
        long long nxt = (one+two)%k;
        if (nxt==b && one==a) {
            cycle.pop_back();
            ps.pop_back(); break;
        }
        cycle.push_back(nxt);
        ps.push_back(nxt+ps.back());
    }

    long long idx = 0;
    long long cum_val = 0;
    for (long long i=0; i<q; i++) {
        long long val;
        cin>>val;
        if (val==0) {cout<<cum_val<<endl; continue;}

        long long res = 0;
        long long rem = idx==0 ? ps.back() : ps.back() - ps[idx-1];
        if (val <= rem) {
            long long tar = val + (idx==0 ? 0 : ps[idx-1]);
            int new_idx = lower_bound(ps.begin(), ps.end(), tar) - ps.begin() + 1;
            res += (new_idx - idx);
            idx = new_idx%cycle.size();
        } else {
            res += ps.size() - idx;
            val -= rem;
            long long c = (val-1)/ps.back();
            val -= c*ps.back();
            res += cycle.size()*c;
            if (val > 0) {
                long long aage = lower_bound(ps.begin(), ps.end(), val) - ps.begin() + 1;
                res += aage;
                idx = (aage)%cycle.size();
            } else {
                idx = 0;
            }
        }
        cum_val += res;
        cout<<cum_val<<'\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
