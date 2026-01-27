// Number of ways to distribute n identical items to k distinct boxes
int starsAndBars(int n, int k) {
    // C(n+k-1, k-1)  // boxes can be empty
    // C(n-1, k-1)    // boxes must have ≥1 item
    return nCr(n + k - 1, k - 1);
}