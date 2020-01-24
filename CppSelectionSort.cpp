#include<bits/stdc++.h>
void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}

using namespace std;
int main()
{
	int a[]={12,21,6,85,1,19};
	int i,j,small,temp;
	for(i=0;i<6;i++)
	{small=i;
		for(j=i+1;j<6;j++)
		{
			if(a[small]>a[j])
			{
				small=j;
			}
		}
	swap(&a[small],&a[i]);
	}
for(i=0;i<6;i++)
{
    cout<<a[i]<<" ";
}
return 0;
}