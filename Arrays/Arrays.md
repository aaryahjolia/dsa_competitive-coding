// This code gives example of one-dimentional and multi-dimentional array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // One-dimentional array
    int num[3];

    num[0] = 10;
    num[1] = 20;
    num[2] = 30;

    for (int i = 0; i < 3; ++i)
    {
        cout << num[i] << " ";
    }
    // Multi-dimentional array
    int nums[][2] = {{1, 2}, {3, 4}};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << nums[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}