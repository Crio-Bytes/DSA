#include <bits/stdc++.h>
using namespace std;

int maxSubSum(int array[], int n)
{
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    return best;
}

int main()
{
    int array[] =  {-3, 1, -8, 12, 0, -3, 5, -9, 4};
    int n = sizeof(array) / sizeof(array[0]);
    int max = maxSubSum(array, n);
    cout << "Maximum Sub-Array Sum: " << max;
    return 0;
}
