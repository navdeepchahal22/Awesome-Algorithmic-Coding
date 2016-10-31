#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int linear_sieve(int limit)
{
  vector<int> lp(limit+1);
  vector<int> pr;

  for (int i=2; i<=limit; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=limit; ++j)
      lp[i * pr[j]] = pr[j];
  }

  for (int i = 2; i<=limit; ++i) {
    if(lp[i] == i) {
      printf("%d is prime\n", i);
    }	else {
      printf("%d is divisible by %d\n", i, lp[i]);
    }
  }
}
int main(void)
{
    int limit;
    printf("Limit=");
    scanf("%d",&limit);
    linear_sieve(limit);
    return 0;
}
