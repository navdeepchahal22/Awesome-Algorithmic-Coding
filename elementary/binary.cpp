//code for Binary search in cpp
#include <iostream>
using namespace std;
int Binary_Search(int arr[], int size, int desired)
{
	int left = 0, right = size - 1, middle;
	while(left<=right)
	{
		middle = left + (right - left) / 2;
		if(arr[middle] == desired)
			return middle;
		else if(desired < arr[middle])
			right = middle - 1;
		else if(desired > arr[middle])
			left = middle + 1;
	}

	return -1;
}
int Lower_Bound(int arr[], int size, int desired)
{
	int left = -1, right = size, middle;
	while (right - left > 1)
	{
		middle = left + (right - left) / 2;
		if (arr[middle] < desired)
		{
			left = middle;
		}	
		else
		{
			right = middle;	
		}
	}
	return right;
}
int Upper_Bound(int arr[], int size, int desired)
{
	int left = -1, right = size, middle;
	while (right - left > 1)
	{
		middle = left + (right - left) / 2;

		if (arr[middle] <= desired)
			left = middle;
		else                                                                                                                                                                                                                         right = middle;
	}
	return right;
}
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 5, 7};
	if(Binary_Search(arr, 7, 4) != -1)
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
	if(Binary_Search(arr, 7, 9) != -1)
	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}
	cout << Lower_Bound(arr, 7, 5) << endl;
	cout << Lower_Bound(arr, 7, 6) << endl;
	cout << Upper_Bound(arr, 7, 5) << endl;
	cout << Upper_Bound(arr, 7, 0) << endl;
		return 0;
}
