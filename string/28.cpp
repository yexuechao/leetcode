#include "../define.h"
class Solution {
public:
    int strStr(string haystack, string needle) {
        return KMP(haystack, needle);
    }

    int KMP(const string& str1, const string& str2) {
        if (str2.empty()) {
            return 0;
        }
        if (str1.empty()) {
            return -1;
        }
        vector<int> next = KMPGetNext(str2);
        int i = 0;
        int j = 0;
        int str1_len = str1.size();
        int str2_len = str2.size();
        while(i < str1_len && j < str2_len) {
            if (j == -1 || str1[i] == str2[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == str2.size()) {
            return i - j;
        }
        return -1;
    }

    vector<int> KMPGetNext(const string & str) {
        vector<int> next(str.size(), 0);
        int k = -1;
        int j = 0;
        next[0] = -1;
        while(j < str.size() - 1) {
            if (k == -1 || str[j] == str[k]) {
                ++j;
                ++k;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
        return next;
    }
};