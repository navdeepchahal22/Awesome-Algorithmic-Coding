#include <iostream>

using namespace std;

int min(int num[], int rem[], int s)
{
	int a = 1;
  	while(true)
  	{
		int i;
     	for(i = 0; i < s; i++)
       		if(a%num[i] != rem[i])
        		break;

       	if(i == s)
       		return a;
       	a++;
  	}
  	return a;
}
int main()
{
	int size1,size2;
	cin>>size1;
	int num[size1];
	for(int i=0;i<size1;i++)
	{
		cin>>num[i];
	}
	cin>>size2;
	int rem[size2];
	for(int i=0; i<size2;i++)
	{
		cin>>rem[i];
	}
	int s = sizeof(num) / sizeof(num[0]);
	cout << "Number is " << min(num, rem, s);
	return 0;
}
