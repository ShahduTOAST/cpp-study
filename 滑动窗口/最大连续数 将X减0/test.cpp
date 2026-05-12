#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

namespace MaxContinue1 {
	//https://leetcode.cn/problems/max-consecutive-ones-iii/
    //这个先说暴力思路，就是需要个count统计0出现次数
    // 首先right探路，碰到1没事，0 ++count继续走
    // 然后判断这个串是否合法，不合法就让left++出串直到合法
    int longestOnes(vector<int>& nums, int k) {
        int count = 0, left = 0, right = 0, n = nums.size(), len = 0;
        for (right = 0; right < n; right++) {
            //len = max(len,right - left);  //这里不能这样是{0，0，1} k = 2有bug。
            if (!nums[right]) count++;
            while (count > k) {//不合法出串直到合法
                if (nums[left++] == 0) count--;
            }
            len = max(len, right - left + 1);//+1是全闭，要加1
        }
        return len;
    }
}

namespace MinOperateXTo0 {
	//https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
    //明天补思路，太困了
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int a : nums) sum += a;
        int targe = sum - x;
        int ret = -1;

        if (targe < 0) return -1;
        for (int left = 0, right = 0, tmp = 0; right < nums.size(); right++) {
            tmp += nums[right];
            while (tmp > targe) {
                tmp -= nums[left++];
            }
            if (tmp == targe)
                ret = max(ret, right - left + 1);
        }
        return ret == -1 ? -1 : nums.size() - ret;
    }
}