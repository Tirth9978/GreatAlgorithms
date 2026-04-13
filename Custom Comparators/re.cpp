#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

class Pair{
    public : 
        int a, b;
        Pair(int a , int b){
            this->a = a;
            this->b = b;
        }
};

int main(){


    // Example 1
    int n ;
    cin >> n;
    vector<Pair> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        arr.push_back(Pair(a,b));
    }


    // Sorting : 
    sort(arr.begin() , arr.end() , [](const Pair &x , const Pair &y) {return x.b > y.b ;});


    for(auto x: arr) {
        cout<<x.a << " " << x.b << "\n";
    }



    
}