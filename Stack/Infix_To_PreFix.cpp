#include<iostream>
#include<stack>
using namespace std ;

int priority(char ch){
     if (ch == '^'){
          return 3;
     }
     else if (ch == '/' || ch == '*'){
          return 2;
     }
     else if (ch == '+' || ch =='-'){
          return 1;
     }
     return -1;
}

string reverse(string str){
     for (int i=0;i<str.size()/2;i++){
          swap(str[i],str[str.size()-1-i]);
     }
     return str;
}

string infixToPrefix(string str){
     stack<char> st;
     string ans = "";
     for (int i=0;i<str.size();i++){
          if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')){
               ans += str[i];
          }
          else if (str[i] == '(' ){
               st.push(str[i]);
          }
          else if (str[i] == ')'){
               while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
               }
               st.pop();
          }
          else {
               if (str[i] == '^'){
                    while(!st.empty() && priority(str[i]) <= priority(st.top())){
                         ans += st.top();
                         st.pop();
                    }
               }
               else {
                    while(!st.empty() && priority(str[i]) < priority(st.top())){
                         ans += st.top();
                         st.pop();
                    }
               }
               st.push(str[i]);
          }
     }
     while(!st.empty()){
          ans += st.top();
          st.pop();
     }
     return ans ;
}

int main(){
     string str ;
     cin >> str ;

     str = reverse(str);
     for (int i=0;i<str.size();i++){
          if (str[i] == '('){
               str[i] = ')';
          }
          else if (str[i] == ')'){
               str[i] = '(';
          }
     }
     str = infixToPrefix(str);

     str = reverse(str);
     cout << str << endl;
     return 0;
}