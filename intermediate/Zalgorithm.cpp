#include <iostream>

using namespace std;

void getZarr(string str, int Z[]);

void search(string text, string pattern);

int main()
{
    string text = "sdsdfslslsdjlkdskljaldssdhjklflkjldsfjkl";
    string pattern = "sdhjkl";
    search(text, pattern);
    return 0;
}


void getZarr(string str, int Z[])
{
    int n = str.length(), Left = 0, Right = 0, k;

    for(int i = 1; i < n; i++)
    {
        if(i > Right)
        {
            Left = Right = i;

            while(Right < n && str[Right - Left] == str[Right])
                Right++;

            Z[i] = Right - Left;
            Right--;
        }
        else
        {
            k = i - Left;

            if(Z[k] < Right - i + 1)
                Z[i] = Z[k];
            else
            {
                Left = i;

                while(Right < n && str[Right - Left] == str[Right])
                    Right++;

                Z[i] = Right - Left;
                Right--;
            }
        }
    }
}


void search(string text, string pattern)
{
    string concat = pattern + "$" + text;
    int size = concat.length();
    int *Z = new int[size];

    getZarr(concat, Z);

    for(int i = 0; i < size; i++)
        if(Z[i] == pattern.length())
            cout << "Pattern found at " <<  i - pattern.length() << endl;

    delete[] Z;
}

