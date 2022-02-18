#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char arr[] = {'x', 'y', 'z'};
    string s = "xyyzyzyx";
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    cout << "The sum of arr : is ::" << sum << endl;

    string ans = "";
    for (int i = 0; i < s.size(); i++)

    {
        int temp = 0;
        string t = "";
        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];
            t += s[j];

            cout << temp << " " << t << endl;
            if (temp == sum)
            {
                ans = t;
                break;
            }
        }
    }

    cout << "the ans is : " << ans << endl;
}
