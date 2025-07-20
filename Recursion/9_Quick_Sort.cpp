#include <iostream>
#include <vector>
using namespace std;

int findIndex(vector<int> &arr, int start, int end)
{
     int i = start + 1;
     int j = end;
     int pivort = arr[start];

     while (i <= j)
     {
          while (arr[i] <= pivort && i <= end)
          {
               i++;
          }
          while (arr[j] >= pivort && j >= start)
          {
               j--;
          }
          if (i < j)
          {
               int temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
          }
     }
     swap(arr[start], arr[j]);
     return j;
}

void quickSort(vector<int> &arr, int start, int end)
{
     if (start >= end)
     {
          return;
     }

     int index = findIndex(arr, start, end);
     cout << index << endl;
     quickSort(arr, start, index - 1);
     quickSort(arr, index + 1, end);

     return;
}

int main()
{
     int n;
     cin >> n;
     vector<int> arr(n);

     for (int i = 0; i < arr.size(); i++)
     {
          cin >> arr[i];
     }

     quickSort(arr, 0, arr.size() - 1);
     for (auto x : arr)
     {
          cout << x << " ";
     }
     return 0;
}