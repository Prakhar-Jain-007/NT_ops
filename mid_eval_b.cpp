#include <bits/stdc++.h>
using namespace std;

const int mod = 1000007;

int mod_multiply(int a, int b) {
    return (1LL * a * b)%mod;
}

vector<int>primes;
int x = 1e6+1;
void computePrimes() {
    vector<bool> isPrime(x, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i=2; i*i<x; i++) {
        if (!isPrime[i]) continue;
        for (int j=i*i; j<x; j+=i) {
            isPrime[j] = false;
        }
    }
    for (int i=0; i<x; i++) {
        if (isPrime[i]) {primes.push_back(i);}
    }
}

void solve() {
    int n;
    cin>>n;

    // wth are these questions man 

    // ye mod itna galat kisne diya tha :(
    int req = 1;
    for (auto i:primes) {
        if (i>n) {break;}
        int lvl = 0;
        int temp = n;
        while (temp>0) {
            lvl += temp/i;
            temp/=i;
        }
        req = mod_multiply((mod_multiply(2, lvl) + 1)%mod, req);
    }
    cout << req << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    computePrimes();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
