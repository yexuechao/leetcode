class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> c2num;
        for (size_t i = 0; i < s.size(); i++) {
            if (c2num.find(s[i]) == c2num.end()) {
                c2num[s[i]] = 1;
            } else {
                c2num[s[i]]++;
            }
        }
        for (size_t i = 0; i < t.size(); i++) {
            if (c2num.find(t[i]) == c2num.end()) {
                return false;
            } else {
                c2num[t[i]] -= 1;
                if (c2num[t[i]] < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};