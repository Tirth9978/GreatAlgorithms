#include<iostream>
using namespace std ;

void swap(int & a, int & b){
     int t = a ;
     a = b;
     b = t ;   
     return ;
}

class heap{
     public :
          int arr[100];
          int size ;

          heap(){
               this->size = 0;
          }

          void insert(int num){
               if (size == 99){
                    cout << "There is not any Space :(\n";
                    return ;
               }

               size ++ ;
               int index = size;
               arr[index] = num;

               while(arr[index] > arr[index/2]){
                    swap(arr[index] , arr[index/2]);
                    index = index / 2;
               }
               return ;
          }

          void Delete(){
               if (size == 0){
                    cout << "Heap is Empty :(\n";
                    return ;
               }
               int index = size;
               // swap(arr[1] , arr[index]);
               arr[1] = arr[index];
               cout << arr[1] << arr[index] << "\n";
                
               index = 1;
               size--;
               while(1){
                    if (index <= size && (arr[index] < arr[index * 2] || arr[index] < arr[index * 2 + 1])){
                         if (arr[index * 2] > arr[index * 2 + 1] ){
                              swap(arr[index] , arr[index * 2]);
                              index = index * 2;
                         }
                         else {
                              swap(arr[index] , arr[index * 2 + 1]);
                              index = index * 2 + 1;
                         }
                    }
                    else {
                         return ;
                    }
               }
          }

          void print(){
               for (int i=1;i<=size;i++){
                    cout << arr[i] << " ";
               }
               cout << endl;
          }
};

int main(){
     heap h;

     h.insert(12);
     h.insert(90);
     h.insert(43);
     h.insert(73);
     h.insert(793);
     h.print();
     h.Delete();
     h.print();
     return 0;
}