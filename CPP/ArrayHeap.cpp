#include<bits/stdc++.h>
using namespace std;
int check(int arr[],int n)
{
  int i;
  for(i=n/2-1;i>=0;i--)
  {
    int l=2*i+1;
    int r=2*i+2;
    if(!(arr[i]<arr[l] && arr[i]<arr[r]))
    {
      return 0;
    }
  }
  return 1;
}
int main()
{
  int i,j,n;
  cout<<"Enter n\n";
  cin>>n;

  int arr[n];

  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  if(check(arr,n))
  {
    cout<<"YESS\n";
  }
  else
  {
    cout<<"N\n";
  }

  return 0;
}
