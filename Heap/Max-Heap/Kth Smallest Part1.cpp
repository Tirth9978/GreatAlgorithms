// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    
    void insert(vector<int> &arr,int num){
        arr.push_back(num);
        int index = arr.size() -1;
        while(index >= 0 && arr[index] > arr[(index-1) /2]){
            swap(arr[index] , arr[(index -1 )/2]);
            index =( index - 1 )/2;
        }
        return ;
    }
    
    void deletAndInsert(vector<int> & arr , int num){
        arr[0] = arr[arr.size()-1];
        // arr[arr.size()-1] = num;
        int index = 0;
        while(index < arr.size()){
            int left = (index * 2 ) + 1;
            int right = (index * 2) + 2;
            
            int ref = index;
            if  (left < arr.size() && arr[ref] < arr[left]){
                ref = left;
            }
            if (right < arr.size() && arr[ref] < arr[right]){
                ref = right ;
            }
            if (ref != index){
                swap(arr[ref] , arr[index]);
                index = ref;
            }
            else {
                break;
            }
        }
        
        arr[arr.size()-1] = num;
        index = arr.size() -1;
        while(index >= 0 && arr[index] > arr[(index-1)/2]){
            swap(arr[index] , arr[(index -1)/2]);
            index = (index-1)/2;
        }
        return ;
    }
    
    int kthSmallest(vector<int> &arr, int k) {
        vector<int> newArr ;
        for (int i=0;i<k ;i++){
            insert(newArr,arr[i]);
        }   
        
        for (int i = k ; i< arr.size() ;i++){
            if (newArr.size() != 0 && arr[i] < newArr[0]){
                deletAndInsert(newArr , arr[i]);
            }
        }
        return newArr[0];
    }
};