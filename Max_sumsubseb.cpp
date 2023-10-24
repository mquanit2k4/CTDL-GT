#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n;
    cin >> n;
    int a[1000001];
    for (int i = 0 ; i < n ; i++)
        cin >> a[i];
    int max_sum = a[0];
    int temp_sum = a[0];
    for (int i = 1 ; i < n ; i++)
    {
        temp_sum = max (a[i] , temp_sum+a[i]);
        max_sum = max(temp_sum , max_sum);
    }
    cout << max_sum;
    return 0;
}
