<!--
 * @Author: yoring7 yoring7
 * @Date: 2022-05-28 23:12:06
 * @LastEditors: yoring7 yoring7
 * @LastEditTime: 2022-05-28 23:31:54
 * @FilePath: /Leetcode/22/ReadMe.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
# 括号生成器
深度优先DFS加减枝
1. 当前左右括号都有大于 00 个可以使用的时候，才产生分支；
2. 产生左分支的时候，只看当前是否还有左括号可以使用；
3. 产生右分支的时候，还受到左分支的限制，右边剩余可以使用的括号数量一定得在严格大于左边剩余的数量的时候，才可以产生分支；
4. 在左边和右边剩余的括号数都等于 00 的时候结算。
