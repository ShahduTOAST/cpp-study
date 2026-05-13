#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
namespace HappyMun{
    int BitSquareSum(int n){
        int sum = 0;
        while (n) {
            int j = n % 10;
            sum += (j * j);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        //这里的两种情况可以归为一种，也就是1之后到2然后循环，即最后都会循环。
        // 所以可以用快慢指针判断是否带环+是否为1
        //（严格证明就是总样本是有限的，在我都遍历一次之后无论怎么走都会重复）
        int slow = n, fast = BitSquareSum(n);
        while (slow != fast && slow != 1) {
            slow = BitSquareSum(slow);
            fast = BitSquareSum(BitSquareSum(fast));
        }

        return slow == 1;
    }
}

namespace WaterContainer{
    int maxArea(vector<int>& height) {
        //思路是这样，左右指针，然后选到小的就让他往中间移动，比较留最大值
        //至于为啥能这样，大概的思路是这样
        //1.首先这里相对的小数字没有啥意义，大部分直接跳过就行
        //2.然后就是大数字比较，再往内动的时候，宽度降低，长度后面讨论
        //3.长度变化 a.变小  b.不变  c.变大（仅限于一个长一个短，短的动到长的），如果二者一样的话，那移动之后也是不变（二者取小）
        int left = 0, right = height.size() - 1;
        int v = 0, t = 0;
        while (left < right) {
            v = min(height[left], height[right]) * (right - left);
            if (height[left] < height[right]) left++;
            else right--;
            t = max(v, t);
        }
        return t;
    }
}

int main() {
	return 0;
}