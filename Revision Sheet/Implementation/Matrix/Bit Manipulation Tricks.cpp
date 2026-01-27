// Essential bit operations
int setBit(int num, int pos) { return num | (1 << pos); }
int clearBit(int num, int pos) { return num & ~(1 << pos); }
int toggleBit(int num, int pos) { return num ^ (1 << pos); }
bool checkBit(int num, int pos) { return (num >> pos) & 1; }

// Common patterns
int lowestSetBit = num & -num; // Two's complement trick
int removeLowestBit = num & (num - 1);
bool isPowerOfTwo = num > 0 && (num & (num - 1)) == 0;

// Iterate through subsets of mask
int mask = ...;
for(int subset = mask; subset > 0; subset = (subset - 1) & mask) {
    // Process subset
}

// Count set bits (Brian Kernighan's algorithm)
int countBits(int n) {
     int count = 0;
     while(n) {
          n &= (n - 1);
          count++;
     }
    return count;
}