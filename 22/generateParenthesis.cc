/*
 * @Author: yoring7 yoring7
 * @Date: 2022-05-28 23:13:19
 * @LastEditors: yoring7 yoring7
 * @LastEditTime: 2022-05-28 23:36:22
 * @FilePath: /Leetcode/22/generateParenthesis.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 1. 当前左右括号都有大于 00 个可以使用的时候，才产生分支；
// 2. 产生左分支的时候，只看当前是否还有左括号可以使用；
// 3. 产生右分支的时候，还受到左分支的限制，右边剩余可以使用的括号数量一定得在严格大于左边剩余的数量的时候，才可以产生分支；
// 4. 在左边和右边剩余的括号数都等于 00 的时候结算。

class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        string str = "";
        generateParenthesis(n, n, str, result);
        return result;
    }

    // 左括号剩余数量，右括号剩余数量，当前字符串，结果
    void generateParenthesis(int left, int right, string str, vector<string> &result)
    {
        // 左右括号剩余数量都为0，说明一个串已经拼接完成
        if (left == 0 && right == 0)
        {
            result.push_back(str);
            return;
        }
        // 剪枝
        if (left > right)
        {
            return;
        }
        // 左括号剩余数量大于0，可以拼接左括号
        if (left > 0)
        {
            generateParenthesis(left - 1, right, str + '(', result);
        }

        if (right > 0)
        {
            generateParenthesis(left, right - 1, str + ')', result);
        }
    }

};

int main()
{
    Solution sol;
    vector<string> result = sol.generateParenthesis(2);
    for (auto str : result)
    {
        cout << str << endl;
    }
    return 0;
}