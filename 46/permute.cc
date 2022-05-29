/*
 * @Author: yoring7 yoring7
 * @Date: 2022-05-29 23:09:59
 * @LastEditors: yoring7 yoring7
 * @LastEditTime: 2022-05-29 23:13:16
 * @FilePath: /Leetcode/46/permute.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue; // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int> > result = sol.permute(nums);
    for (auto vec : result)
    {
        for (auto num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}