class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }
        vector<string> words = split(s, " ");
        for (size_t i = 0; i < words.size(); i++) {
            reverse(words[i].begin(), words[i].end());
        }
        // 拼接
        string result;
        for (size_t i = 0; i < words.size(); i++) {
            result += words[i] + " ";
        }
        if (!result.empty()) {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    // void ReverseWordsCore(string& s, int head, int tail) {
    //     while(head < tail) {
    //         swap(s[head], s[tail]);
    //     }
    // }

    vector<string> split(const string& str, const string& delim) {
        vector<string> res;
        if("" == str) return res;
        //先将要切割的字符串从string类型转换为char*类型
        char * strs = new char[str.length() + 1] ; //不要忘了
        strcpy(strs, str.c_str());

        char * d = new char[delim.length() + 1];
        strcpy(d, delim.c_str());

        char *p = strtok(strs, d);
        while(p) {
            string s = p; //分割得到的字符串转换为string类型
            res.push_back(s); //存入结果数组
            p = strtok(NULL, d);
        }

        return res;
    }
};