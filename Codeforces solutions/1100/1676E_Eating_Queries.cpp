#include <bits/stdc++.h>
using namespace std;
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define mod 1000000007
#define ull unsigned long long
#define ll long long int
#define fastread()                                     \
    (ios_base::sync_with_stdio(false), cin.tie(NULL)); \
    cout.tie(NULL);
int main()
{
    fastread();
    w(t)
    {
        int n, q;
        cin >> n >> q;
        vector<ll> arr(n), sum(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        sum[0] = arr[0];
        for (int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + arr[i];

        while (q--)
        {
            ll x;
            cin >> x;
            int start = 0, end = n-1, res = -1;
            while (start <= end)
            {
                int mid = start+ (end -start) / 2;
                if (sum[mid] >= x) // mid = index of candies 
                {
                    res = mid+1; // total candies required (index+1)
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
