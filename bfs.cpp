#include<bits/stdc++.h>
using namespace std;
vector<int> V[2001];
int max_level = -1;
void dfs(int x,int level)
{
  if(level>max_level)
  {
    max_level = level;
  }
  for(int i=0;i<V[x].size();i++)
  {
    dfs(V[x][i],level+1);
  }

}
int main()
{
  int n,i;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
    if(arr[i]!=-1)
    {
      V[arr[i]].push_back(i+1);
    }
    else
    {
      V[0].push_back(i+1);
    }
  }
  for(i=0;i<V[0].size();i++)
  {
    dfs(V[0][i],1);
  }

  cout<<max_level<<"\n";
  return 0;
}
