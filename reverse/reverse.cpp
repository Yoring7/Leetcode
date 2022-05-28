#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
        int result = 0;

        while (x)
        {
            if (result < -2147483648 / 10 || result > 2147483647 / 10)
                return 0;
            result = result * 10 + (x % 10);
            x /= 10;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int x = -123;
    cout << sol.reverse(x) << endl;
}