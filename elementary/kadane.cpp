//Kadane Algorithm
#include <iostream>
using namespace std;
int kdn(int given[], int n) 
{
	int cur_max=0, max_so_far=0;
	for(int i=0;i<n;i++)
	{
		cur_max=max(0, cur_max+given[i]);
		max_so_far=max(max_so_far,cur_max);
	}
	return max_so_far; 
}
int main()
{
	int max_subarr_sum;
	int given[]={-2, 1, -6, 4, -1, 2, 1, -5, 4};
	int n=sizeof(given)/sizeof(given[0]); 
	int fl=0; 
	int largest_in_negative = given[0]; 
	for(int i = 0; i < n; i++) 
	{
		if(given[i]>=0) 
		{
			fl=1;
			break;
		}
		else if(given[i]>largest_in_negative)
		{
			largest_in_negative=given[i];
		}
	}
	if(fl == 1) 
	{
		max_subarr_sum = kdn(given, n);
	}
	else
	{
		max_subarr_sum = largest_in_negative; 
	}
	cout << "Maximum Subarray Sum is " << max_subarr_sum << endl;
	return 0;
}
