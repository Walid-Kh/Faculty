#include <bits/stdc++.h>
using namespace std;
bool found = false; 
int counter = 1; 
// (((aπ(1) o1 aπ(2)) o2 aπ(3)) o3 aπ(4)) o4 aπ(5)
void possible(int *arr, int size, int res)
{
  int skip = 1;
  int op[] = {0, 0, 0};
  // leaf
  if (found)
  {
    return;
  }
  if (size == 0)
  {
    cout << res << " " <<counter++ << endl;
    found |= res == 6; 
    return;
  }
  // initial case
  if (size == 5)
  {
    skip = 2;
    op[0] = arr[0] * arr[1];
    op[1] = arr[0] - arr[1];
    op[2] = arr[0] + arr[1];
  }
  // general case
  else
  {
    op[0] = res * (*arr);
    op[1] = res - (*arr);
    op[2] = res + (*arr);
  }
  possible(arr + skip, size - skip, op[0]);
  possible(arr + skip, size - skip, op[1]);
  possible(arr + skip, size - skip, op[2]);
}
bool possible(int *arr, int size)
{
  int res = 0;
  possible(arr, size, res);
  return found; 
}
int main()
{
  int n;
  cin >> n;
  for (int j = 0; j < n; j++)
  {

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
      cin >> arr[i];
    }
    bool res = possible(arr, 5);
    if (res)
      cout << "Possible" << endl;
    else
      cout << "Impossible" << endl;
  }
  return 0;
}