#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int multiply(int a, int b, int len);
int main()
{
    int a = 1234, b = 4568;
    int x;
    int len = 0;
    x =a;
    while(x>0)
    {
        x = x/10;
        len++;
    }
    cout <<"len "<< len << endl;
    int result = multiply(a,b,len);
    cout << "result1 ==" << result << endl;
    return 0;
   
}

int multiply(int a, int b, int len)
{
  if(len == 1)
  {
      return a*b;
  }
  int a1, b1, c1, d1;
   
  a1 = a/(pow(10.0, double(len/2)));
  cout << "a1 = " << a1 << endl;
  b1 = a%(int)(pow(10.0, double(len/2)));
  cout << "b1 = " << b1 << endl; 
  c1 = b/(pow(10.0, double(len/2)));
  cout << "c1 = " << c1 << endl;
  d1 = b%(int)(pow(10.0, double(len/2)));
  cout << "d1 = " << d1 << endl;
  
  int m = multiply(a1,c1,len/2);
  int n = multiply(b1,c1,len/2);
  int m1 = multiply(a1,d1,len/2);
  int n1 = multiply(b1,d1,len/2);
  
  double result = pow(10.0,double(len))*m + pow(10.0,double(len/2))*(n+m1)+n1;
  
  cout << "result ==" << result << endl;
  
  return result;
   
}