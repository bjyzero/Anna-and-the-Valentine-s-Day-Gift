/// 一个博弈问题
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(const int &Case)
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), b(n);
    for (auto &x : arr)
        cin >> x;

    int s = 0; // 记录总的数字长度
    for (int i = 0; i < n; ++i)
    {
        while (arr[i] % 10 == 0)
        {
            arr[i] /= 10;
            s++;
            b[i]++;
        }
        while (arr[i])
        {
            arr[i] /= 10;
            s++;
        }
    }

    sort(b.begin(), b.end(), greater<int>()); // 按照从大到小的顺序排序

    // Anna 先去掉末尾处 0 位数最多的数字
    // 而 Sasha 维护接下来末尾处 0 位数最多的数字
    for (int i = 0; i < n; i += 2)
    {
        s -= b[i];
    }

    puts(s <= m ? "Anna" : "Sasha");
}

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve(i);
    }
    return 0;
}