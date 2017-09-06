#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> data;
int n;

int bsearch(int x , int l , int h)
{
  if(l > h) return -1;

  int m = (l + h) / 2;
  if(data[m] == x)
  {
    return m;
  }

  else
  {

    if(x < data[m]) return bsearch(x , l , m-1);
    else return bsearch (x , m+1 , h);
  }
}

int main()
{
  cin>>n;
  data.resize(n);
  for(int i = 0 ; i < n ; i++)
  {
    cin>>data[i];
  }

  sort(data.begin() , data.end());
  for(int i = 0 ; i < data.size() ; i++) cout<<data[i]<<" ";
  cout<<endl;
  cout<<"query : ";
  int x;
  cin>>x;

  cout<<bsearch(x , 0 , data.size()-1)<<endl;return 0;
}
