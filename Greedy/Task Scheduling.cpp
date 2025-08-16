#include <bits/stdc++.h>
using namespace std ;

struct Task
{
     int start , finish;
};

bool cmp(Task a,Task b) {
     return a.start < b.start;
}

int minMachine(vector<Task> & task){
     sort(task.begin(),task.end(),cmp);
     priority_queue<int , vector<int> ,greater<int>> pq;

     for (auto t : task){
          if (!pq.empty() && pq.top() <= t.start){
               pq.pop();
          }

          pq.push(t.finish);
     }

     return pq.size();
}

int main() {
     
     return 0;
}