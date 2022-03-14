#include <bits/stdc++.h>
using namespace std;
bool found = false;
int counter = 1;
// (((aπ(1) o1 aπ(2)) o2 aπ(3)) o3 aπ(4)) o4 aπ(5)
/* void possible(int *arr, int size, int res, string x = "")
{
  int skip = 1;
  int op[] = {0, 0, 0};
  vector<string> y(3);
  // leaf
  if (found)
  {
    return;
  }
  if (size == 0)
  {
    cout << res << " : " << counter++ << " : " << x << endl;
    found |= res == 23;
    return;
  }
  // initial case
  if (size == 5)
  {
    skip = 2;
    op[0] = arr[0] * arr[1];
    y[0] = "*";
    op[1] = arr[0] - arr[1];
    y[1] = "-";
    op[2] = arr[0] + arr[1];
    y[2] = "+";
  }
  // general case
  else
  {
    op[0] = res * (*arr);
    y[0] = x + "*";
    op[1] = res - (*arr);
    y[1] = x + "-";
    op[2] = res + (*arr);
    y[2] = x + "+";
  }
  possible(arr + skip, size - skip, op[0], y[0]);
  possible(arr + skip, size - skip, op[1], y[1]);
  possible(arr + skip, size - skip, op[2], y[2]);
}
bool possible(int *arr, int size)
{
  int res = 0;
  possible(arr, size, res);
  return found;
} */
int arr[5];
bool possible(int cur, int a)
{
  if (a == 5)
    return cur == 23;
  return possible(cur + arr[a], a + 1) ||
         possible(cur - arr[a], a + 1) ||
         possible(cur * arr[a], a + 1);
}
int main()
{
  for (int i = 0; i < 5; i++)
  {
    cin >> arr[i];
  }
  bool pos = possible(arr[0], 1);
  do
  {
    pos = possible(arr[0], 1); 
    if (pos) break; 
    // next_permutation return a bool which is true when it hasn't finished
    // it rearages the arr to give all the possible combinations 
    // given the elements in the arr 
    // the array has to be sorted for this to work 
    // so you have to call sort(ptrfirst,ptrfirst+size(ptrlast)); 
    // for example the arr = {1,2,3} has the following permutations
    //  1 2 3
    //  1 3 2
    //  2 1 3
    //  2 3 1
    //  3 1 2
    //  3 2 1
    // takes a pointer to the first element and a pointer to the last elements 
  } while (next_permutation(arr, arr + 5));
  cout << pos << endl ;
  return 0;
}