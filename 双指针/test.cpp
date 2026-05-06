#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include<string>
using namespace std;

void RemoveZero() {
	//https://leetcode.cn/problems/move-zeroes/
    class Solution {
    public:
        void moveZeroes(vector<int>* nums) {
            for (int cur = 0, dest = -1; cur < nums->size(); cur++) {
                if ((*nums)[cur]) {//处理不为零
                    swap(nums[cur], nums[++dest]);
                }
            }

        }
    };
}
void DuplicateZero() {
	//https://leetcode.cn/problems/duplicate-zeros/
    class Solution {
    public:
        void duplicateZeros(vector<int>& arr) {
            int cur = 0, dest = -1, n = arr.size();
            //找结束位置,没0都走1，有0dest多走1
            while (cur < n) {
                if (arr[cur]) {
                    dest++;
                }
                else{
                    dest += 2;
                }
                if (dest >= n - 1) break;
                cur++;
            }
            //处理特殊情况.dest越界
            if (dest == n) {
                arr[n - 1] = 0;
                cur--; dest -= 2;
            }
            //返回复写，遇到零写两次，其他直接覆盖
            while (cur >= 0) {
                if (arr[cur]) arr[dest--] = arr[cur--];
                else {
                    arr[dest--] = 0;
                    arr[dest--] = 0;
                    cur--;
                }
            }
        }
    };
}

int main() {

	return 0;
}
