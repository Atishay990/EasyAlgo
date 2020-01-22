#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int i,int n)
{
  int smallest=i;
  int l=2*i+1;
  int r=2*i+2;

  if(l<n && arr[l]<arr[smallest])
  {
    smallest=l;
  }
  if(r<n && arr[r]<arr[smallest])
  {
    smallest=r;
  }
  if(smallest!=i)
  {
    swap(arr[i],arr[smallest]);
    heapify(arr,smallest,n);;
  }
}
void Kthlargest(int arr[],int n,int k)
{
  int i;
  for(i=k/2-1;i>=0;i--)
  {
    heapify(arr,i,k);
  }
  for(i=k;i<n;i++)
  {
    if(arr[i]>arr[0])
    {
      arr[0]=arr[i];
      heapify(arr,0,k);
    }
  }

}
int main()
{
  int i,n,k;
  cout<<"enter n\n";
  cin>>n;
  int arr[n];

  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  cout<<"enter k \n";
  cin>>k;
  Kthlargest(arr,n,k);
  cout<<arr[0];
  return 0;
}
