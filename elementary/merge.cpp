//Code for merge sort
#include <iostream>
using namespace std;
int *tmp;
void conquer_merge(int arr[], int left, int right, int mid)
{
	int k = left, i, j;
	for(i = left, j=mid + 1; i<=mid && j<=right; k++)
	{
		if(arr[i]<=arr[j])
		{
			tmp[k]=arr[i];
			i++;
		}
		else
		{
			tmp[k] = arr[j];
			j++;
		}
	}
	while(i <= mid)
	{
		tmp[k] = arr[i];
		i++;
		k++;
	}
	while(j <= right)
	{
		tmp[k] = arr[j];
		j++;
		k++;
	}
	for(i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}
void divi(int arr[], int left, int right)
{
	if(left < right)
	{
		int mid = left + (right - left) / 2;

		divi(arr, left, mid);
		divi(arr, mid + 1, right);

		conquer_merge(arr, left, right, mid);
	}
}
void Merge_Sort(int arr[], int size)
{
	tmp = new int[size];
	divi(arr, 0, size - 1);
	delete [] tmp;
}
void Print_Array(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = {2, 4, 3, 1, 6, 8, 4};
	Merge_Sort(arr, 7);
	Print_Array(arr, 7);
	return 0;
}
