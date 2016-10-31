#include<iostream>
#include <cmath>
#define MAX 100000000
using namespace std;
void prime(int n, int *primes)
{
	int i,j,count=0;

	primes[count++] = 2;
	if (count == n)
		return;
	for(i=3;i<=MAX;i+=2)
	{
		int isPrime=1;
		int jMax = sqrt(i);
		for(j=3;j<=jMax;j+=2)
		{
			if(i%j==0)
			{
				isPrime=0;
				break;
			}
		}
		if(isPrime)
		{
			primes[count++] = i;
			if(count==n)
				return;
		}
	}
}

int main()
{
	int n,i;

	cin>>n;
	int arr[n];
	int maxPrime = 0;

	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		if (arr[i] > maxPrime)
			maxPrime = arr[i];
	}
	int primes[maxPrime];
	prime(maxPrime, primes);
	for (i=0;i<n;i++)
	{
		cout<<primes[arr[i]-1];
		cout<<"\n";
	}
	return 0;
}
