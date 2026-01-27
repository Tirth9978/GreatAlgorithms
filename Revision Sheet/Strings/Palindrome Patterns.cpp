// Expand around center - most efficient
int expandAroundCenter(string& s, int left, int right) {
    while(left >= 0 && right < s.size() && s[left] == s[right]) {
        left--; right++;
    }
    return right - left - 1; // length of palindrome
}

// Check if palindrome
bool isPalindrome(string& s, int l, int r) {
    while(l < r && s[l] == s[r]) l++, r--;
    return l >= r;
}

// Trick: For longest palindromic substring, expand from each center
// O(n²) time, O(1) space