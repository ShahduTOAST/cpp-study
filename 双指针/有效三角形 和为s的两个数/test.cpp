#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

namespace SumS {
	//https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/description/
	//这个思路就很简单了，因为数组是有序的，所以直接判断和大小然后对应移动left和right
    vector<int> twoSum(vector<int>& price, int target) {
        int left = 0, right = price.size() - 1, sum;
        while (left < right) {
            sum = price[left] + price[right];
            if (target > sum) left++;
            else if (target < sum) right--;
            else return { price[left], price[right] };
        }
        //处理不成立（虽然不可能）
        return{ -1,-1 };
    }
}

namespace EffectiveTriangle {
	//https://leetcode.cn/problems/valid-triangle-number/description/
    //这个思路是这样，和上面一个题一样要用单调性。
    //首先有一个基于单调性的结论，a+b>c（这里a<b<c）成立即可判断三角形,因为c>a,c>b, 在加个数更大
    //然后我们先固定c，开始a,b一左一右动，如果a+b>c那么ab之间的数也都大于，直接+(b-a)即可
    int triangleNumber(vector<int>& nums) {
        int sum = 0;
        //排序
        sort(nums.begin(), nums.end());
        //固定c找符合条件个数
        for (int i = nums.size() - 1; i > 1; i--) {
            int left = 0, right = i - 1;
            while (left < right) {
                if ((nums[left] + nums[right]) <= nums[i]) left++;
                else {
                    sum += (right - left);
                    right--;
                }
            }
        }
        return sum;
    }
}