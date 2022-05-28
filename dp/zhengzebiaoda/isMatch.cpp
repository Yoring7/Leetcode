#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
// 正则表达式匹配
    bool isMatch(string s, string p) 
    {
        int s_len = s.length();
        int p_len = p.length();
        int s_index = 0;
        int p_index = 0;
        char last;


        while(p_index < p_len && s_index < s_len)
        {
            last = p[p_index];
            if (p[p_index] != '.' && p[p_index] != '*' && p[p_index] != s[s_index])
                break;
            while ((p[p_index] == '.' || p[p_index] == s[s_index]) && s_index < s_len && p_index < p_len)
            {
                last = p[p_index];
                s_index++;
                p_index++;
            }
            while (p[p_index] == '*')
            {
                if (last == '.')
                    return true;
                if (last == s[s_index])
                    s_index++;
                else
                    p_index++;
            }
        }
        if (p_index < p_len && p_index > 0)
        {
            if (p[p_index - 1] == '*' && p[p_index] == '.')
                p_index++;
            else if (p[p_index] == '.')
                return false;

            for(; p[p_index] == '*'; p_index++);
        }

        return s_index == s_len && p_index == p_len;
    }
};



int main()
{
    Solution sol;
    string s = "aab";
    string p = "c*a*b";
    cout << sol.isMatch(s, p) << endl;
}