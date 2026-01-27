int farthest = 0;
for(int i = 0; i < n; i++){
    if(i > farthest) return false; // Can't proceed
    farthest = max(farthest, i + arr[i]);
}