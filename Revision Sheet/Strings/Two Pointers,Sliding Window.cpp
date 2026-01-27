// Pattern: One pointer at start, one at end, or slow/fast
int left = 0, right = s.size() - 1;
while(left < right) {
    // Process s[left] and s[right]
    left++; right--;
}

// Sliding window template
int left = 0, maxLen = 0;
unordered_map<char, int> freq;
for(int right = 0; right < s.size(); right++) {
    freq[s[right]]++;
    while(windowInvalid(freq)) { // Condition
        freq[s[left]]--;
        left++;
    }
    maxLen = max(maxLen, right - left + 1);
}