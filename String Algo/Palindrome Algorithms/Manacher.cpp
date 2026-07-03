#include<iostream>
#include<string>
#include<vector>
using namespace std ;

class Manacher {
    private : 
        vector<int> p;
        string Mstring ;
    public : 
        void Build(string s) {
            cout << "Building String for Manacher\n";
            string t = "";
            for (auto x: s) {
                t += '#' + x;
            }
            t += "#";
            Mstring = t;
            return ;
        }
        void MakeMArray(){
            cout << "Building array for Manacher\n";
            int n = (int)Mstring.size();
            p = vector<int> (n,1);
            int l = 1;
            int r = 1;
            for (int i=1;i<n;i++) {
                p[i]=max(0,min(r-i , p[l+r-i]));

                while(i - p[i] >=0 && i + p[i] < n && Mstring[i-p[i]] == Mstring[i+p[i]]){
                    p[i] ++ ;
                }
                if (p[i] + i > r) {
                    r = p[i] + i;
                    l = i - p[i];
                }
            }
            return ;
        }
        void PrintArray(){
            for (auto x : p) cout << x << " ";
            cout << endl;
            return ;
        }
};


int main(){
    Manacher m;
    m.Build("abababababc");
    m.MakeMArray();
    m.PrintArray();
    return 0;
}
