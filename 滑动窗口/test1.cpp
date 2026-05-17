 vector<int> findAnagrams(string s, string p) {
        int hash[26] = { 0 };//统计p
        int hash1[26] = { 0 };
        vector<int> ret;
        for(auto it: p ){
            hash[it - 'a']++;
        }
        
        for(int left = 0,right = 0, count = 0;right<s.size();right++){
            if(++hash1[s[right] - 'a'] <= hash[s[right]-'a']) count++;
            if(right-left +1 > p.size()){
                char out = s[left++];
                if(hash1[out -'a']-- <= hash[out -'a']) count--;
            }
            if(count==p.size()) ret.push_back(left);
        }
        return ret;
    }
