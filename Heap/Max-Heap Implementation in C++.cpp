#include<iostream>
#include<vector>
using namespace std ;

class maxHeap {
     public : 
          vector<int> heap;

          int parent(int i) { return (i - 1) / 2; }
          int left(int i) { return 2 * i + 1; }
          int right(int i) { return 2 * i + 2; }

          int getMax() {
               if (heap.empty()){
                    return -1;
               }
               return heap[0];
          }
          void printHeap() {
               for (int val : heap) cout << val << " ";
               cout << endl;
          }
          
};