//code for bucket 
#include <iostream>
using namespace std;
void counti_sort(int input[], int n)
{
	int result[n]; 
	int max = input[0];
	int min = input[0];
	for(int i = 1; i < n; i++)
	{
		if(input[i] > max)
		{
			max = input[i];
		}
		else if(input[i] < min)
		{
			min = input[i];
		} 
	}
	int k = max - min + 1;
	int count_array[k]; 
	fill_n(count_array, k, 0);
	for(int i = 0; i < n; i++)
	{
		count_array[input[i] - min]++;
	}
	for(int i = 1; i < k; i++)
	{
		count_array[i] += count_array[i - 1];
	}
	for(int i = 0; i < n; i++)
	{
		result[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}
	for(int i = 0; i < n; i++)
	{
		input[i] = result[i]; 
	}

}

int main()
{
	int n = 9,i;
	int input[] = {1, 5, 2, 7, 3, 4, 4, 1, 5};
	counti_sort(input, n);
	cout << "Sorted Array : ";
	for(i = 0; i < n; i++)
		cout << input[i] << "  ";
	return 0;
}

