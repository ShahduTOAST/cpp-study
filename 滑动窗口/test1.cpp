//https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
//这个提的思路的话1.我们要找所有子符出现个数相同的串，所以我们需要统计字符出现次数，然后让长度为M的串从往右走，如果他符合要求就入表
//所以定义两个指针，右往前走探路，因为我们只关心字符出现个数，所以用两个哈希表
//如果右指针指向的字符是目标字符就count++，一直往后走直到长度过长
//然后维护长度，让左指针++，然后维护count，也是如果left执行那个的是有效元素，就让count--，否则不变
//然后找个地方更新统计结果，这里是维护好有效的串后判断是不是目标，也就是count是不是等于p的长度，是的话就标记
vector<int> findAnagrams(string s, string p) {
        int hash[26] = { 0 };//统计p
        int hash1[26] = { 0 };
        vector<int> ret;
        for(auto it: p ){//统计p的数据出现次数
            hash[it - 'a']++;
        }
        
        for(int left = 0,right = 0, count = 0;right<s.size();right++){
            if(++hash1[s[right] - 'a'] <= hash[s[right]-'a']) count++;//如果符合要求(也就是是正确元素就count++)
            if(right-left +1 > p.size()){
                char out = s[left++];
                if(hash1[out -'a']-- <= hash[out -'a']) count--;//维护count，如果是符合要求的字符就让count--
            }
            if(count==p.size()) ret.push_back(left);//如果有效字符个数和目标长度一样就记录
        }
        return ret;
    }
