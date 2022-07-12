#include <bits/stdc++.h>
using namespace std;
struct usingnumber
{
    long long num[20000] = {0};
    int len = 0;
};
usingnumber jian(usingnumber a, usingnumber b) //前导0的处理 负数的处理
{
    usingnumber ans;
    //比较大小先
    if (a.len > b.len)
        ans.num[0] = 0;
    else if (b.len > a.len)
    {
        swap(a, b);
        ans.num[0] = 1;
    }
    else
    {
        for (int i = a.len; i >= 1; i--) //
        {
            if (a.num[i] > b.num[i])
            {
                ans.num[0] = 0;
                break;
            }
            else if (a.num[i] < b.num[i])
            {
                ans.num[0] = 1;
                break;
            }
        }
    } //比较大小比完了；ans【0】代表的就是正负数
    //此时a的大小恒大于b，无脑a-b就可以了
    ans.len = a.len;
    for (int i = 1; i <= a.len; i++)
    {
        if (a.num[i] + ans.num[i] >= b.num[i] && a.num[i] >= 0)
            ans.num[i] += a.num[i] - b.num[i];
        else
        {
            ans.num[i + 1]--;
            ans.num[i] += a.num[i] - b.num[i] + 10;
        }
    }
    //除去多余的0
    for (int j = a.len; j > 1; j--)
    {
        if (ans.num[j] == 0)
            ans.len--;
        else
            break;
    }
    return ans;
}
usingnumber cy(usingnumber a, long long b) //除法(高精度/低精度)
{
    usingnumber ans;
    ans.len = a.len;
    for (int j = a.len; j >= 1; j--)
    {
        ans.num[j] = a.num[j] / b;
        a.num[j - 1] += 10 * (a.num[j] % b);
    }
    for (int i = a.len; i > 1 && ans.num[i] == 0; i--) //处理前导0
        ans.len--;
    return ans;
}
usingnumber add(usingnumber a, usingnumber b)
{
    usingnumber ans;
    ans.len = max(a.len, b.len);
    for (int i = 1; i <= max(a.len, b.len); i++)
    {
        ans.num[i] += a.num[i] + b.num[i];
        ans.num[i + 1] += ans.num[i] / 10;
        ans.num[i] %= 10;
    }
    if (ans.num[ans.len + 1] > 0)
        ans.len++;
    return ans;
}
usingnumber xxx(usingnumber a, usingnumber b) //乘法
{
    usingnumber ans;
    ans.len = a.len + b.len - 1;
    for (int i = 1; i <= a.len; i++)
        for (int j = 1; j <= b.len; j++)
        {
            ans.num[i + j - 1] += a.num[i] * b.num[j];
            ans.num[i + j] += ans.num[i + j - 1] / 10;
            ans.num[i + j - 1] %= 10;
        }
    if (ans.num[ans.len + 1] > 0)
        ans.len++;
    return ans;
}
void output(usingnumber numbers) //把数字调正后输出
{
    if (numbers.num[0] == 1)
        cout << "-";
    for (int i = numbers.len; i >= 1; i--)
    {
        cout << numbers.num[i];
    }
}
usingnumber stringtoint(string input) //字符串从0位开始存储，数字从第一个数组开始储存
{
    usingnumber ans;
    ans.len = input.size();
    for (int i = input.size() - 1; i >= 0; i--) // string 的第一位为0
    {
        ans.num[input.size() - i] = input[i] - '0';
    }
    return ans;
}
int main()
{
    long long b;
    string a;
    cin >> a >> b;
    output(cy(stringtoint(a), b));
    return 0;
}