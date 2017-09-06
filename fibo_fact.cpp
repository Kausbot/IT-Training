#include<iostream>
using namespace std;

long long fib(int x)
{
  if(x <= 1) return 1;
  else
  {
    return fib(x-1) + fib(x-2);
  }
}

long long fact(int x)
{
  if(x <= 1) return 1;
  else
  {
    return x*fact(x-1);
  }
}

int main()
{
  int x,y;
  cin>>x>>y;
  cout<<"fibonacci "<<x<<" is "<<fib(x)<<endl;
  cout<<"factorial "<<y<<" is "<<fact(y)<<endl;

  return 0;
}
