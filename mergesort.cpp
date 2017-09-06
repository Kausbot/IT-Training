#include <iostream>
#include <vector>

using namespace std;

vector <int> data;
int n;


void merge(int p , int q , int r)
{
  int x= p;
  int y = q+1;

  //we have 2 arrays p to q-1 and q to r..

  vector <int> temp;

  while(x < q+1 && y < r+1)
  {
    if(data[x] < data[y])
    {
      temp.push_back(data[x]);
      x++;
    }

    else
    {
      temp.push_back(data[y]);
      y++;
    }
  }


  //exit condition...
  if(x == q+1)
  while(y <=r)
  {
    temp.push_back(data[y]);
    y++;
  }

  if(y == r+1)
  while(x <= q)
  {
    temp.push_back(data[x]);
    x++;
  }

  cout<<"p: "<<p<<" q: "<<q<<" r: "<<r<<endl;
  cout<<"temp: ";
  for(int i = 0 ; i< temp.size() ; i++) cout<<temp[i]<<" ";
  cout<<endl;

  for(int i = p ; i <= r ; i++) data[i] = temp[i - p];
  for(int i = 0 ; i < n ; i++) cout<<data[i]<<" ";
  cout<<endl<<endl;

}

void mergesort(int p , int r)
{


  int q = (p + r) / 2;

  if( p < q)
  {
    mergesort(p , q);
    mergesort(q+1, r);
  }
  merge(p , q , r);

}


int main()
{
  cin>>n;
  data.resize(n);

  for(int i = 0 ; i < n ; i++)
  {
    cin>>data[i];
  }

  mergesort(0 , n-1);
}
