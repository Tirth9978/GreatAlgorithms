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

          void Insert(int num) {
               heap.push_back(num);
               int i=heap.size()-1;
               while (i > 0 && heap[i] > heap[parent(i)]){
                    swap(heap[i] , heap[parent(i)]);
                    i = parent(i);
               }
          }

          void removeRoot(){
               swap(heap[0],heap[heap.size()-1]);
               heap.pop_back();
               int i = 0;
               int leftChild  = left(i);
               int rightChild = right(i);

               while(heap[i] < heap[leftChild] || heap[i] < heap[rightChild]){
                    int willSwap = leftChild;
                    if (heap[leftChild] < heap[rightChild]){
                         willSwap = rightChild ;
                    }

                    swap(heap[i] , heap[willSwap]);

                    i = willSwap;
                    leftChild = left(i);
                    rightChild = right(i);
               }

          }
          
};

int main(){
     maxHeap mx ;
     mx.Insert(13);
     mx.Insert(20);
     mx.Insert(4);
     mx.Insert(12);
     mx.Insert(17);
     mx.Insert(15);
     mx.Insert(15);
     mx.Insert(13);
     mx.Insert(10);
     mx.Insert(29);
     

     mx.removeRoot();
     mx.printHeap();

     return 0;
}