<!--
 * @Author: yoring7 yoring7
 * @Date: 2022-05-30 00:12:57
 * @LastEditors: yoring7 yoring7
 * @LastEditTime: 2022-05-30 00:14:17
 * @FilePath: /Leetcode/46/ReadMe.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
# 全排列
深度优先、回溯算法

backtrack的公式：

result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择