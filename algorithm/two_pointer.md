
# 双指针
```c++
一种经典思路是初始化p的字符数组然后维护数组每个元素不小于0。 
开始向右滑动窗口，减去并相应字符，如果频率小于0就收缩左侧边界直到频率不再小于0。
窗口长度与p长度一致时达成条件。 cpp代码如下。执行时间4ms，击败99%。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if(m < n) return {};
        vector<int> hashTable(26);
        for(auto ch : p) ++hashTable[ch - 'a'];
        vector<int> ret;
        for(int l = 0, r = 0; r < m; ++r) {
            --hashTable[s[r] - 'a'];
            while(hashTable[s[r] - 'a'] < 0) {
                ++hashTable[s[l] - 'a'];
                ++l;
            }
            if(r - l + 1 == n) ret.push_back(l);
        }
        return ret;
    }
};
```
