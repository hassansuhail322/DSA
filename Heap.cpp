#include<iostream>
#include<algorithm>
using namespace std;
void insert_in_heap(int a[],int element,int size)
{
	
	a[size]=element;
 	int i=size;

 	while(i>=0 && a[i]>a[(i-1)/2])
 	{
 		int temp=a[i];
 		a[i]=a[(i-1)/2];
 		a[(i-1)/2]=temp;
 		i=(i-1)/2;
 	}


}




int main()
{
	int a[50]={50,30,20,10,15,5};
	insert_in_heap(a,90,6);
for(int i=0;i<7;i++)
{
	cout<<a[i]<<endl;
}

	return 0;
}