#include <iostream>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll B = 131;

vector<int> rabinKarp(const string &T, const string &P)
{
    int n = T.size();
    int m = P.size();

    if (m == 0 || m > n)
        return {};

    // Compute B^(m-1) % MOD
    ll powB = 1;
    for (int i = 0; i < m - 1; i++)
        powB = (powB * B) % MOD;

    ll hp = 0; // Pattern hash
    ll ht = 0; // Text hash

    // Initial hash
    for (int i = 0; i < m; i++)
    {
        hp = (hp * B + P[i]) % MOD;
        ht = (ht * B + T[i]) % MOD;
    }

    vector<int> ans;

    for (int i = 0; i <= n - m; i++)
    {
        // Hash matched
        if (hp == ht)
        {
            bool ok = true;

            // Verify to avoid collision
            for (int j = 0; j < m; j++)
            {
                if (T[i + j] != P[j])
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans.push_back(i);
        }

        // Rolling hash update
        if (i < n - m)
        {
            ht = (ht - (T[i] * powB) % MOD + MOD) % MOD;
            ht = (ht * B + T[i + m]) % MOD;
        }
    }

    return ans;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> result = rabinKarp(text, pattern);

    cout << "Pattern found at indices: ";
    for (int idx : result)
        cout << idx << " ";

    return 0;
}
