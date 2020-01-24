#include<bits/stdc++.h>
using namespace std;
class Graph
{
  int V;
  list<int> *adj;

public:
  Graph(int V);
  void addEdge(int v,int w);
  void connectedComponents();
  void DFSUtil(int v,bool visited[]);
};
Graph::Graph(int V)
{
  this->V=V;
  adj = new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
  adj[v].push_back(w);
  adj[w].push_back(v);
}
void Graph:: DFSUtil(int v,bool visited[])
{
  visited[v]=true;
  cout<<v<<" ";
  list<int>::iterator i;
  for(i=adj[v].begin();i!=adj[v].end();i++)
  {
    if(!visited[*i])
    {
      DFSUtil(*i,visited);
    }
  }
}
void Graph::connectedComponents()
{
  bool *visited = new bool[V];
  int i;
  for(i=0;i<V;i++)
  {
    visited[i]=false;
  }
  for(i=0;i<V;i++)
  {
    if(visited[i]==false)
    {
      DFSUtil(i,visited);
      cout<<"\n";
    }
  }

}
int main()
{
  Graph g(5);
  g.addEdge(1,0);
  g.addEdge(2,3);
  g.addEdge(3,4);

  g.connectedComponents();
}
