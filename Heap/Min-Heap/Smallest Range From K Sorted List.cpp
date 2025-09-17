#include<bits/stdc++.h>
#include <climits>
class node{
    public :
        int data ;
        int i ; 
        int j ;

        node(int data , int i , int j){
            this->data = data;
            this->i = i ;
            this->j = j;
        }
};

class com{
    public :
        bool operator()(node * a , node * b){
            return a->data > b -> data;
        }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int ansStart = INT_MAX;
    int ansEnd = INT_MIN;

    priority_queue<node* , vector<node*> , com> minHeap;

    for (int i=0;i<a.size();i++){
        minHeap.push(new node(a[i][0],i,0));
        maxi = max(maxi , a[i][0]);
        mini = min(mini , a[i][0]);
    }

    ansStart = mini;
    ansEnd = maxi;    

    while(!minHeap.empty()){
        node * top = minHeap.top();
        minHeap.pop();

        mini = top->data ;
        int i = top->i;
        int j = top->j;

        if (maxi - mini < ansEnd-ansStart){
            ansEnd= maxi;
            ansStart = mini;
        }

        if (j < a[i].size()-1){
            minHeap.push(new node(a[i][j+1] , i,j+1));
            maxi = max(maxi, a[i][j+1]);
        }
        else {
            break;
        }

    }

    return ansEnd - ansStart + 1;
}