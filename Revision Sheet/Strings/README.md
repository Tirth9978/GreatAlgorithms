## C++ Specific Tips : 
```
// Fast I/O for strings
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// String operations
s.find("sub"); // returns index or string::npos
s.substr(start, length); // O(length) time
s += "append"; // O(1) amortized
s = s + "append"; // O(n) - creates new string!

// Use stringstream for parsing
stringstream ss(s);
string token;
while(getline(ss, token, delimiter)) {
    // process token
}

// Reserve memory to avoid reallocations
string result;
result.reserve(n); // If you know final size

// Convert between string and numeric
int num = stoi(s);
string str = to_string(num);

// Character checking functions
```

## Common Mistakes : 
- Using `s.length()` in loop with modification inside
- Using `substr` in loop causing O(n²) time
