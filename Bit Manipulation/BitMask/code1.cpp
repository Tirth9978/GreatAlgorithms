/*
Consider this problem: There are N≤5000
 workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30]
, representing his/her availability. You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
     int n;
     cin >> n;
     vector<int> mask(n,0);
     for (int i=0;i<n;i++){
          int num_days ;
          cin >> num_days;
          int mask1 = 0;
          for (int i=0;i<num_days;i++){
               int day ;
               cin >> day;
          
               mask1 = mask1 | (1 << day);
          }
          mask[i] = mask1;
     }
     for (int i=0;i<mask.size();i++){
          for (int j=i+1;j<mask.size();j++){
               int intersection = mask[i] & mask[j];
               int num_days = __builtin_popcount(intersection);

          }
     }
     return 0;
}