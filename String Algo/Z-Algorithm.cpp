#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include<algorithm>
using namespace std;


int main()
{
     auto zFunction = [&](string s) -> vector<long long>
     {
          vector<long long> z(s.size(), 0);
          long long l = 0;
          long long r = 0;
          for (int i = 1; i < (long long)s.size(); i++)
          {
               if (i < r)
               {
                    z[i] = min((long long)r - i, z[i - l]);
               }
               while (i + z[i] < (long long)s.size() && s[z[i]] == s[i + z[i]])
               {
                    z[i]++;
               }
               if (i + z[i] > r)
               {
                    l = i;
                    r = i + z[i];
               }
          }

          return z;
     };

     string s;
     cin >> s;
     vector<long long> z = zFunction(s);
     vector<int> borders;

     for (int i = 1; i < (long long)s.size(); i++)
     {
          if (i + z[i] == (long long) s.size())
               borders.push_back(z[i]);
     }

     sort(borders.begin(), borders.end());

     for (int x : borders)
          cout << x << " ";
     return 0;
}
