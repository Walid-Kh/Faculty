#include <bits/stdc++.h>
using namespace std;
/*
  -----Recursion----- 

  Tower of Hanoi 
  the problem states that we have some number of disks on one pole 
  we have to move these disk to a destination using a auxilary 
  a bigger disk cannot be place one top of a smaller disk
  however opposite is false 
  this problem can only be solved using recursion* (needs research)

  the base case in that recursion is if the number of disks is 1 if that's 
  the case we're done
  the general case here is our strategy say we have 3 disks

    -  <- we have to move these two to the aux pole
    __ <-
    ___
  and then move the largest of the disks to the destination 
  these two steps are the first two lines of code 
  the last line move the rest of disks now on the aux to the destination using the
  same strategy
*/
void solveTowers (int num, char source, char des, char aux)
{
  if (num == 1)
  {
    cout << "Move form " << source << " to " << des << endl; 
    return; 
  }
  else 
  {
    solveTowers(num-1, source, aux, des); 
    solveTowers(1, source, des, aux); 
    solveTowers(num-1, aux, des, source); 
  }
}
template <class T>
void printarr (T* arr, int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " "; 
  cout << endl; 
}
/* 
  a lot of math problem adverticed as recursion problem can be solved in 
  constant time complexity such as factorials 
  factorials are nothing more that a 
  geometeric series 2, 4, 8, 16
  a_n = r*a_(n-1)
  the sum of the elements from m to n 
  (k=m)Σ(n) a_k = a_m * (1-r^n) / (1-r)
  the product of the element from m to n
  (k=m)Π(n) a_k = sqrt(( (a_m * a_(n-1))^(n) )
  where           a_m = a_1 * r^(m-1)
  




*/

int main ()
{
  // testing purposes
  int a[15]; 
  a[0] = 2; 
  long product = 1; 
  for (int i = 1; i < 15; i++)
    a[i] = 2*a[i-1];
  for (int i =0; i < 6; i++)
    product *= a[i]; 
  cout << (int) sqrt((long)pow((long)a[0]*a[5],6)) << " " << product << endl; 
  return 0;
}