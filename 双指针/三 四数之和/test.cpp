#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

namespace ThreeNumsAdd{
//https://leetcode.cn/problems/3sum/
	//这个和两个数之和还有水桶的很题类似，也是固定一个然后开始动，但是这个有些特殊情况要处理
	//思路就是先定一个然后双指针开始动，去除重复
	//这里就有一些问题1.怎么去重复  2.他和2numsadd不太一样，需要所有可能，所以条件需要改
	//重复怎么去除，很简单，碰到重复元素直接跳过就好了，所以这里就有三地方个需要跳过
	//但是跳过也就又有新问题，越界咋办？这个我想的是循环加个判断条件
    //这里循环判断条件是看当前和上一个是否相等，所以就要先++一次
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ret;
        //排序
        sort(nums.begin(), nums.end());
        //这里循环条件顺序涉及到了会不会崩溃,我这里有个优化（当最小数都比0大直接不成立）
        for (int i = 0; i < nums.size() - 2 && (nums[i] <= 0);) {
            int left = i + 1, right = nums.size() - 1;


            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum > -nums[i])  right--;
                else if (sum < -nums[i]) left++;
                else {
                    ret.push_back({ nums[i],nums[left],nums[right] });
                    left++, right--;
                    //跳过重复
                    while ((right > left) && nums[right] == nums[right + 1]) { right--; }
                    while ((right > left) && nums[left] == nums[left - 1]) { left++; }
                }
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1]) i++;

        }
        return ret;
    }
}

namespace FourNumsAdd {
//https://leetcode.cn/problems/4sum/description/
    //这个咋说呢，就是你想的三数之和+循环，没啥难度了
    //这里中有一个很难绷的坑，size()的返回类型是size_t
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ret;
        //排序
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size();) {

            for (int i = j + 1; i < nums.size();) {
                int left = i + 1, right = nums.size() - 1;
                long long aim = (long long)target - nums[i] - nums[j];

                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum > aim)  right--;
                    else if (sum < aim) left++;
                    else {
                        ret.push_back({ nums[j],nums[i],nums[left++],nums[right--] });
                        //跳过重复
                        while ((right > left) && nums[right] == nums[right + 1]) { right--; }
                        while ((right > left) && nums[left] == nums[left - 1]) { left++; }
                    }
                }
                i++;
                while (i < nums.size() && nums[i] == nums[i - 1]) i++;
            }
            j++;
            while (j < nums.size() && nums[j] == nums[j - 1]) j++;
        }
        return ret;
    }
}

int main() {
	return 0;
}
