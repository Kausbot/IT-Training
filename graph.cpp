#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class graph
{
public:
  int V;
  vector< vector <int> > adj;

  vector <bool> visited;

  graph(int v)
  {
    this->V = v;
    adj.resize(V);
  }

  void add_edge(int u , int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void dfs_r(int x)
  {
    visited.assign(V,false);
    dfs_util(x);
  }

  void dfs_util(int x)
  {
    if(visited[x]) return;
    else
    {
      visited[x] = true;
      cout<<"visited "<<x<<endl;

      for(auto it = adj[x].begin() ; it != adj[x].end(); it++ )
      {
        dfs_util(*it);
        //cout<<"back to "<<*it<<endl;
      }
    }
  }

  void dfs_i(int x)
  {
    visited.assign(V,false);
    stack <int> st;
    st.push(x);

    while(!st.empty())
    {
      int temp = st.top();
      st.pop();
      if(!visited[temp])
      {
        visited[temp] = true;
        cout<<"visited "<<temp<<endl;

        for(auto it = adj[temp].begin(); it!= adj[temp].end(); it++)
        {
          st.push(*it);
          //cout<<"pushed "<<*it<<endl;
        }
      }


    }

  }


  void bfs(int x)
  {
    visited.assign(V,false);
    queue <int> q;
    q.push(x);

    while(!q.empty())
    {
      int temp = q.front();     //top changed to front...
      if(!visited[temp])
      {
        visited[temp] = true;
        cout<<"visited "<<temp<<endl;

        for(auto it = adj[temp].begin(); it!= adj[temp].end(); it++)
        {
          q.push(*it);
        }
      }

      q.pop();
    }

  }




};


int main()
{
  //test case 1
  graph g1(9);

  g1.add_edge(0,8);
  g1.add_edge(0,1);
  g1.add_edge(0,7);

  g1.add_edge(1,2);

  g1.add_edge(2,7);
  g1.add_edge(2,3);
  g1.add_edge(2,4);

  g1.add_edge(3,4);
  g1.add_edge(3,6);

  g1.add_edge(4,5);


  //cmd area..
  //dfs_r dfs_i bfs..



  //test case 2 - a tree..
  graph g2(9);

  g2.add_edge(0,1);
  g2.add_edge(0,4);

  g2.add_edge(1,2);
  g2.add_edge(1,3);

  g2.add_edge(4,5);
  g2.add_edge(4,6);

  g2.add_edge(6,7);
  g2.add_edge(6,8);

  //cmd area
  cout<<"bfs"<<endl;
  g1.bfs(0);
  cout<<endl<<"dfs"<<endl;
  g1.dfs_i(0);
  return 0;
}
