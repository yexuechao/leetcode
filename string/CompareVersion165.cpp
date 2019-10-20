class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1, ".");
        vector<string> v2 = split(version2, ".");
        int size = min(v1.size(), v2.size());
        for (int i = 0; i < size; i++) {
            int n1 = atoi(v1[i].c_str());
            int n2 = atoi(v2[i].c_str());
            if (n1 == n2) {
                continue;
            } else if (n1 < n2){
                return -1;
            } else {
                return 1;
            }
        }
        if (v1.size() > size) {
            for (int i = size; i < v1.size(); i++) {
                int n = atoi(v1[i].c_str());
                if (n > 0) {
                    return 1;
                }
            }
        } else {
            for (int i = size; i < v2.size(); i++) {
                int n = atoi(v2[i].c_str());
                if (n > 0) {
                    return -1;
                }
            }
        }
        return 0;
    }
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