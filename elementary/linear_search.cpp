//linear search code
#include <iostream>

using namespace std;
int Linear_Search(int array[], int size, int desired);


int main(){
    int size;
    cin >>size;
    int array[10000];
    int des;
    for(int i=0; i<size;i++)
	{
	    cin>>array[i];
	}
    cin>>des;
    if(Linear_Search(array, size, des) != -1)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
int Linear_Search(int array[], int size, int desired)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == desired)
            return i;
    }

    return -1;
}
