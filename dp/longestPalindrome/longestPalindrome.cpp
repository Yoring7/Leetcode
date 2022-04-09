#include<iostream>
#include<string>
#include<vector>
using namespace std;


/**
 * 动态规划
 * dp数组含义
 * 递归公式
 * 遍历顺序
 */


/**
 * @brief 最长回文子串
 * 
 * @param s 
 * @return string 
 */
string longestPalindrome(string s)
{
    int n = s.size();
    if(n == 0)
        return "";
    if(n == 1)
        return s;
    int max_len = 1;
    int max_start = 0;
    int max_end = 0;
    for(int i = 0; i < n; i++)
    {
        // 奇数
        int len = 1;
        int j = i - 1;
        int k = i + 1;
        // 两个指针分别指向i的两侧，如果两侧值相等则向外拓展
        while(j >= 0 && k < n && s[j] == s[k])
        {
            len += 2;
            j--;
            k++;
        }
        // 比较现有的值和原值大小
        if(len > max_len)
        {
            max_len = len;
            max_start = j + 1;
            max_end = k - 1;
        }
        // 偶数
        len = 0;
        j = i;
        k = i + 1;
        while(j >= 0 && k < n && s[j] == s[k])
        {
            len += 2;
            j--;
            k++;
        }
        if(len > max_len)
        {
            max_len = len;
            max_start = j + 1;
            max_end = k - 1;
        }
    }
    return s.substr(max_start, max_len);
}


// 最长回文子串动态规划
string longestPalindromePD(string s)
{
    int size = s.size();
    if(size == 0)
        return "";
    if(size == 1)
        return s;
    // dp数组下标表示从i到j的子串 如果为true则说明这个子串为回文串
    // https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
    vector<vector<bool> > dp(size, vector<bool>(size, false));
    int max_len = 1;
    int max_start = 0;
    int max_end = 0;
    for(int i = 0; i < size; i++)
    {
        dp[i][i] = true;
    }
    for (int j = 1; j < size; j++)
    {
        for(int i = 0; i < j; i++)
        {
            if (s[i] == s[j])
            {
                if (j - i < 3)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
            else
                dp[i][j] = false;
            
            // 判断是否最长
            if (dp[i][j] && j - i + 1 > max_len)
            {
                max_len = j - i + 1;
                max_start = i;
            }
        }
    }

    return s.substr(max_start, max_len);
}




int main()
{
    // 测试用例
    string s = "babad";
    cout << longestPalindromePD(s) << endl;
    
    string s1 = "cbbd";
    cout << longestPalindromePD(s1) << endl;
    return 0;
}