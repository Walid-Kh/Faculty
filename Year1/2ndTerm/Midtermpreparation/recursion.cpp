#include <bits/stdc++.h>
using namespace std;
 
//https://docs.google.com/presentation/d/1ZjPHCM1J-WGLqNzJLAheGLQAPYwtA0kI0fqzu_o7q28/edit#slide=id.p1 
//p1
void binaryN (int n,string res="")
{
  if (res.size() == n)
  {
    cout << res << "\n" ;
    return; 
  }
  binaryN(n,res+'0'); 
  binaryN(n,res+'1'); 
}
// p2
void baseKN (int k, int n, string res = "")
{
  if (res.size() == n)
  {
    cout << res << '\n'; 
    return; 
  }
  for (int i = 0; i < k; i++)
  {
    baseKN(k,n,res+to_string(i));
  }
}
// p3
int possibleWaysToRunUpAStair (int n)
{
  if (n < 0)
    return 0; 
  if (n == 0)
    return 1;
  return possibleWaysToRunUpAStair(n-1) + possibleWaysToRunUpAStair(n-2) + possibleWaysToRunUpAStair(n-3); 
}

int main ()
{
  cout << possibleWaysToRunUpAStair(3); 
  return 0;
}