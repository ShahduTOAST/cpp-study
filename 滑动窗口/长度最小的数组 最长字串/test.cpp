#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

 namespace MinArr{
 //https://leetcode.cn/problems/minimum-size-subarray-sum/description/
	 //这个题的思路的话，首先我们先明确数组的和是单调递增的(元素均大于0)
	 //暴力思路是，我们确定left，right。然后让right往右走直到找到满足条件的位置返回长度
	 //然后left++继续。
	 //下面是优化，首先我们知道他递增的情况就可以不用让right再回来重走一遍，也是为啥上面找到一个就可以停下了
	 //然后left++也就相当于减少了，也没不要让right再走一遍
	 // (这里你可能说为啥不能是第二次刚好完全包住第一次，这里如果他包住的话，那么就会有个问题，
	 // 如果内部成立那么外部必然成立，也就是根本不会在right+1处才停下，肯定在right就结束了，所以这个情况不成立)
	 // 所以我们可以让left++判断，在做下一步决策[和双指针很类似]
     int minSubArrayLen(int target, vector<int>& nums) {
         int n = nums.size(), sum = 0, len = INT_MAX;
         for (int left = 0, right = 0; right < n; right++) {
             sum += nums[right];
             while (sum >= target) {
                 len = min(len, right - left + 1);
                 sum -= nums[left++];
             }
         }
         len = len == INT_MAX ? 0 : len;
         return len;
     }
}

 namespace MaxString{
 //https://leetcode.cn/problems/longest-substring-without-repeating-characters/
     //思路是这样，首先解法还是滑动窗口，因为他的暴力解法和上面类似
     //然后思路是我入数据，然后检查是否重复，重复就left--然后继续
     int lengthOfLongestSubstring(string s) {
         int left = 0, right = 0, n = s.size(), ret = 0;
         int hash[128] = { 0 };
         while (right < n) {
             hash[s[right]]++;//入哈希表
             while (hash[s[right]] > 1)//判断是否有重复元素
                 hash[s[left++]]--;//出哈希
             ret = max(ret, right - left + 1);//更新
             right++;

         }
         return ret;
     }
 }
int main(){
	return 0;
}