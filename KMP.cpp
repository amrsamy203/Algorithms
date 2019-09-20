#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string p) {
    int n = (int)p.size();
    vector<int> f(n, 0);
    for(int i = 1, k = 0; i < n; i++) {
        while(k && p[i] != p[k]) {
            k = f[k-1];
        }
        if(p[k] == p[i]) {
            f[i] = ++k;
        } else {
            f[i] = k;
        }
    }
    return f;
}

void kmp(string s, string p) {
    int n = (int)s.size(), m = (int)p.size();
    vector<int> f = failure(p);
    for(int i = 0, k = 0; i < n; i++) {
        while(k && p[k] != s[i]) {
            k = f[k-1];
        }
        if(p[k] == s[i]) {
            k++;
        }
        if(k == m) {
            cout << "match at: " << i-m+1 << endl;
            k = f[k-1];
        }
    }
}

int main () {
    string s, p;
    s = "abxababaaba"; // 0 0 0 1 2 1 2 1 1 2 1
    p = "aba"; // 0 0 1
    kmp(s, p);
}
