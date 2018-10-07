#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])	largest=l;
	if(r<n && arr[r]>arr[largest])	largest=r;
	if(largest!=i)
	{
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapify(arr, n, largest);
	}
}
void heapsort(int arr[], int n)
{
	for(int i=n/2-1; i>=0; i--)		heapify(arr, n, i);
	for(int i=n-1; i>=0; i--)
	{
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		n--;
		heapify(arr, i, 0);
	}
}
void printarray(int arr[], int n)
{
	for(int i=0; i<n; i++)		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
	int arr[10], n;
	cout<<"\nEnter n : ";
	cin>>n;
	for(int i=0; i<n; i++)		cin>>arr[i];
	heapsort(arr, n);
	cout<<"\nThe sorted array : ";
	printarray(arr, n);
	return 0;
}
