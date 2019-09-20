//solution for https://www.spoj.com/problems/ADACLEAN/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5;

int mod[2] = {1000000093, 1000000103}; // 2 prime mod should be less than 2e9 to avoid overflow
int base[2] = {97, 257}; // 2 prime bases.
int base_power[2][MAXN]; // all powers for bases.

int main() {
    for(int r = 0; r < 2; r++) { ///// calculating bases powers.
        base_power[r][0] = 1;
        for(int i = 1; i < MAXN; i++) {
            base_power[r][i] = 1ll * base[r] * base_power[r][i-1] % mod[r];
        }
    }

    int T, n, k;
    char s[MAXN];

    int hash[2][MAXN]; // comulative hash array
    unordered_set<ll> hashes; // set of double hashes

    scanf("%d", &T);
    while(T--) {
        hashes.clear();
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        for(int r = 0; r < 2; r++) {
            for(int i = 0; i < n; i++) { // building comulative hash array.
                hash[r][i] = ((i ? hash[r][i-1] : 0) + 1ll * s[i] * base_power[r][i]) % mod[r];
            }
        }
        int hsh[2]; //
        for(int i = 0; i <= n-k; i++) {
            for(int r = 0; r < 2; r++) { // hashing using 2 different hash functions.
                hsh[r] = 1ll * (hash[r][i+k-1] - (i ? hash[r][i-1] : 0) + mod[r]) * base_power[r][n-k-i] % mod[r];
            }
            hashes.insert(hsh[0]*1e9+hsh[1]); // push the double hash to set.
        }
        printf("%d\n", (int)hashes.size());
    }
}
