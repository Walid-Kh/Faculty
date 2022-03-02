#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
  void reverseString (vector<char>& s)
  {
    reverseString(&s[0], s.size()); 
  }
  void reverseString (char* s, int size)
  {
    if (size <= 1)
      return; 
      char temp = s[0]; 
      s[0] = s[size-1]; 
      s[size-1] = temp; 
      reverseString(s+1,size-2); 
  }
};
int main()
{
  vector<char> x = {'H','a','n','n','a','h'};
  solution s;
  s.reverseString(x);  
  for (auto i : x)
    cout << i; 
  return 0;
}