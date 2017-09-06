#include <iostream>
#include <string>
#include <vector>

using namespace std;
string s1,s2;

vector<bool> incl;

int lcs(int p , int q)
{
  if(p < 0 || q < 0) return 0;
  else
  {
    if(s1[p] == s2[q])
    {
      if(!incl[s1[p]-'a'])
      {
        incl[s1[p]- 'a'] = true;
        cout<<s1[p]<<" ";
      }
      return 1 + lcs(p-1 , q-1);
    }

    else return max(lcs(p-1,q), lcs(p,q-1));
  }
}

int main()
{

  incl.assign(26,false);

  cin>>s1>>s2;

  int p = s1.size() -1;
  int q = s2.size() -1;
  cout<< lcs(p,q)<<endl;

  return 0;
}
