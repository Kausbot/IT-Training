#include <iostream>
#include <vector>

using namespace std;

vector <int> data;
int n;

int partition(int l , int r)
{
  // for any array last element is pivot
  // we just have to rearrange it..

  int x = l-1;  //partition boundary..
  for(int i = l ; i < r ; i++)
  {
    if(data[i] <= data[r]) // left partition condition
    {
      x++ ;
      swap(data[x], data[i]);
    }
  }

  swap(data[x+1] , data[r]);
  //put back pivot..

  //print
  for(int i = l ; i <= r ; i++) cout<<data[i]<<" "; cout<<"pivot is "<<data[x+1];
  cout<<endl;

  return x+1;

}

void quicksort(int p , int r)
{
  if(p >= r) return;
  int q = partition(p , r);

  quicksort(p , q-1);
  quicksort(q , r);
}


int main()
{
    cin>>n;
    data.resize(n);
    for(int i = 0 ; i < n ; i++)
    {
      cin>>data[i];
    }

    quicksort(0 , n-1);

    cout<<endl;
    for(int i = 0 ; i < n ; i++) cout<<data[i]<<" ";
    cout<<endl;

  return 0;
}
