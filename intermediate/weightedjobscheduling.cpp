#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

class WeightedInterval {
public:
    int start, finish, weight;

    bool operator < (const WeightedInterval& x) const   {
        if (finish != x.finish)
            return finish < x.finish;
        return start < x.start;
    }
} *intervals;

int binary_search(int lo, int hi, int val)   {
    int mid;
    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (intervals[mid].finish <= val)
            lo = mid;
        else
            hi = mid - 1;
    }
    if (intervals[lo].finish > val)
        return 0;
    return lo;
}

int greatestNonOverlappingInterval(int i)   {
    return binary_search(0, i-1, intervals[i].start);
}

int main()  {
    int N, i, *dp, *p;

    scanf("%d", &N); 
    intervals = new WeightedInterval[N + 1];
    for (i = 1; i <= N; i++)
        scanf("%d %d %d", &intervals[i].start, &intervals[i].finish, &intervals[i].weight);

    intervals[0].start = intervals[0].finish = intervals[0].weight = 0;

    sort(intervals + 1, intervals + N + 1);

    dp = new int[N + 1];
    p = new int[N + 1];
    dp[0] = p[0] = 0;

    for (i = 1; i <= N; i++)    {
        p[i] = greatestNonOverlappingInterval(i);
        dp[i] = max(intervals[i].weight + dp[p[i]], dp[i-1]);
    }

    stack <int> opt;
    for (i = N; i > 0; )    {
        if (intervals[i].weight + dp[p[i]] >= dp[i-1])  {
            opt.push(i);
            i = p[i];
        } else
            i--;
    }
    printf("%d\n", dp[N]);
    while (!opt.empty())    {
        i = opt.top();
        opt.pop();
        printf("%d %d %d\n", intervals[i].start, intervals[i].finish, intervals[i].weight);
    }

    return 0;
}
