// printing all subsequence whose sum is k

#include "bits/stdc++.h"
using namespace std;
void print(int i, int n, int arr[], vector<int> &sub, int sum, int k)
{
    if (i > n)
    {
        if (sum == k)
        {
            for (auto it : sub)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    sub.push_back(arr[i]);
    sum = sum + arr[i];
    print(i + 1, n, arr, sub, sum, k);
    sum = sum - arr[i];
    sub.pop_back();
    print(i + 1, n, arr, sub, sum, k);
}

int main()
{
    int arr[] = {1, 2, 1};
    int k = 0;
    vector<int> sub;
    print(0, 3, arr, sub, 0, k);
}