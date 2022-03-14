#include <bits/stdc++.h>
using namespace std;
void oldschoolmessanging()
{
  int t;
  cin >> t;
  string *x = new string[t];
  for (int i = 0; i < t; i++)
  {
    cin >> x[i];
  }
  for (int i = 0; i < t; i++)
  {
    int count = 0;
    for (int j = 0; j < x[i].size(); j++)
    {
      count += (x[i][j]-96) ; 
    }
    cout << count << " "; 
  }
}
int main()
{
  oldschoolmessanging(); 
  return 0;
}