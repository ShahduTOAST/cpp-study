namespace Friut {
    //https://leetcode.cn/problems/fruit-into-baskets/
    //这个暴力思路，定义左右，然后开始统计水果种类数，然后合法right++，不合法出哈希left--；
    //主要是还没学哈希
    int totalFruit(vector<int>& f) {
        unordered_map<int, int> hash;//统计水果种类
        int ret = 0;
        for (int left = 0, right = 0; right < f.size(); right++) {
            hash[f[right]]++;
            while (hash.size() > 2) {//判断+出窗口
                hash[f[left]]--;
                if (hash[f[left]] == 0)
                    hash.erase(f[left]);
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
}
