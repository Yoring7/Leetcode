/*
 * @Author: yoring7 yoring7
 * @Date: 2022-05-28 22:03:01
 * @LastEditors: yoring7 yoring7
 * @LastEditTime: 2022-05-28 22:16:21
 * @FilePath: /Leetcode/19/removeNthFromEnd.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
 #include <iostream>
 #include <string>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 双指针法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *slow_ptr = head;
        ListNode *fast_ptr = head;
        
        // 首先快指针先往前走n步
        for (int i = 0; i < n; i++)
        {
            fast_ptr = fast_ptr->next;
        }
        // 如果走到头了，就直接把头删去
        if (fast_ptr == nullptr)
        {
            return head->next;
        }
        // 快指针先往前走，直到快指针指向头
        while (fast_ptr->next != nullptr)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        slow_ptr->next = slow_ptr->next->next;
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = sol.removeNthFromEnd(head, 1);
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
    return 0;
}