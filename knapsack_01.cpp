#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }

void knapsack(int n,int w[],int val[],int m)
{
  int i,j;
  int mat[m+1][n+1];
  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
    {
      if(i==0||j==0)
      {
        mat[i][j]=0;
      }
      else
      {
        if(w[i-1]<=j)
        {
          mat[i][j]=max(val[i-1]+mat[i-1][j-w[i-1]],mat[i-1][j]);
        }
        else
        {
          mat[i][j]=mat[i-1][j];
        }
      }
    }
  }
  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }

  int maxfun=mat[m][n];
	int minmoney=0;
	for(i=0;i<=n;i++)
	{
		if(mat[m][i]==maxfun)
		{
			minmoney=i;
			break;
		}
	}
	printf("%d %d\n",minmoney,maxfun);
 //cout<<sum<<" "<<mat[m][n]<<endl;
 cout<<"\n";

}
int main()
{
  int bud,par,i,j;
  while(true)
  {
    cin>>bud;
    cin>>par;
    if(bud==0 && par==0)
    {
      break;
    }
    int w[par];
    int val[par];
    for(i=0;i<par;i++)
    {
      cin>>w[i];
      cin>>val[i];
    }
    int t1,t2;
//    for(i=0;i<par;i++)
    {
      for(j=i+1;j<par;j++)
      {
        if(w[j]<w[i])
        {
          t1=w[j];
          w[j]=w[i];
          w[i]=t1;

          t2=val[j];
          val[j]=val[i];
          val[i]=t2;
        }
      }
    }
    knapsack(bud,w,val,par);
  }
  return 0;
}
