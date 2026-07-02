#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int mod_multiply (int a, int b) {
    return (1LL*(a%mod)*(b%mod))%mod;
}

vector<vector<int>> mat_multiply(const vector<vector<int>>&a, const vector<vector<int>>&b) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                res[i][j] = (mod_multiply(a[i][k], b[k][j]) + res[i][j])%mod;
            }
        }
    }
    return res;
}

vector<vector<int>> mat_exp(const vector<vector<int>>&mat, long long power) {
    int n = mat.size();
    vector<vector<int>> idy(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {idy[i][i] = 1;}
    if (power==0) {return idy;}
    if (power%2==1) {return mat_multiply(mat_exp(mat, power-1), mat);}
    return mat_exp(mat_multiply(mat, mat), power/2);
}

void solve() {
    long long n;
    cin>>n;

    if (n==1) {cout<<2<<endl; return;}
    if (n==0) {cout<<0<<endl; return;}
    if (n<0) {cout<<-1<<endl; return;}

    // need binary exponentiation here
    vector<vector<int>> mat = {{1, 1}, {1, 0}};
    auto res = mat_exp(mat, n);
    
    long long req = (1LL*res[0][0] + 1LL*res[0][1] + 1LL*res[1][0] + 1LL*res[1][1])%mod;
    cout<<req<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
