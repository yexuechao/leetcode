class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.empty() || needle.size() > haystack.size()) {
            return -1;
        }
        int size = needle.size();
        for (size_t i = 0; i <= (haystack.size() - size); i++) {
            string str = haystack.substr(i, size);
            if (str == needle) {
                return i;
            }
        }
        return -1;
    }
};