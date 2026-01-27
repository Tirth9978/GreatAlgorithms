// Pattern: Sort then process sequentially
sort(arr.begin(), arr.end(), [](auto& a, auto& b){
    // Critical: Choose sorting key carefully!
    // For intervals: sort by end time, not start
    return a.end < b.end; // Classic interval scheduling
});