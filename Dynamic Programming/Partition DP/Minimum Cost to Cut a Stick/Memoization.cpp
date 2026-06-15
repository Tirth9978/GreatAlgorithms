class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;

    int solve(int i, int j, vvt &dp, vt &cuts) {

        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mn = INT_MAX;

        for (int k = i; k <= j; k++) {

            int cost =
                cuts[j + 1] - cuts[i - 1]
                + solve(i, k - 1, dp, cuts)
                + solve(k + 1, j, dp, cuts);

            mn = min(mn, cost);
        }

        return dp[i][j] = mn;
    }

    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int m = cuts.size();

        vvt dp(m, vt(m, -1));

        return solve(1, m - 2, dp, cuts);
    }
};
