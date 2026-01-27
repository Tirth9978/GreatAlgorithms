## 🎯 Quick Core Ideas :
- One move at a time, make best local choice → hope for global optimum
- Two properties needed: Greedy choice property + Optimal substructure
- Key question: "If I make this choice now, can I still achieve optimal?"

## Exchange Argument Concept 
- Mental model: If swapping two adjacent elements improves solution, keep swapping
- Use: Proving greedy choice is correct
- Example: Arrange numbers for largest number (comparator: a+b > b+a)

## Frequently Asked Problems
- Activity Selection (variants: weighted, rooms needed)
- Minimum platforms for trains (arrival/departure merge)
- Largest number from array (custom sort: a+b vs b+a)
- Jump Game I/II

## C++ Specific Tips
```cpp
// Custom comparator for complex objects
sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
    if(a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1]; // Secondary: longer first
});

// For priority_queue: opposite comparator!
auto cmp = [](pair<int,int> a, pair<int,int> b){
    return a.first > b.first; // Min-heap
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```


