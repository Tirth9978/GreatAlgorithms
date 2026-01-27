// Precompute factorials and inverse factorials modulo MOD
const int MOD = 1e9+7;
const int MAXN = 1e6+5;
vector<long long> fact(MAXN), invFact(MAXN);

void precompute() {
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;
    
    invFact[MAXN-1] = modInverse(fact[MAXN-1], MOD); // Fermat
    for(int i = MAXN-2; i >= 0; i--)
        invFact[i] = invFact[i+1] * (i+1) % MOD;
}

int nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}

vector<vector<int>> C(n+1, vector<int>(n+1, 0));
for(int i=0; i<=n; i++) {
    C[i][0] = C[i][i] = 1;
    for(int j=1; j<i; j++)
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
}