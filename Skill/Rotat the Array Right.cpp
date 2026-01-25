#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    int n = arr.size();

    k %= n;  // handle k > n

    // Right rotate by k
    rotate(arr.begin(), arr.end() - k, arr.end());

    for (int x : arr) cout << x << " ";
}
