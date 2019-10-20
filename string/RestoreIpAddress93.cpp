class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4) {
            return vector<string>();
        }
        restoreIpAddressesCore(s, 0, 3);
        return results;
    }
    void restoreIpAddressesCore(string s, int idx, int remain) {
        if (remain <= 0) {
            string tmp = s.substr(idx);
            if (tmp.size() >= 4 || atoi(tmp.c_str()) > 255) {
                return;
            }
            if (tmp[0] == '0' && tmp.size() != 1) {
                return ;
            }
            cur.push_back(tmp);
            CurToStr();
            cur.pop_back();
            return ;
        }
        for (int i = 1; i <= 3; i++) {
            if (idx + i >= s.size()) {
                break;
            }
            string tmp = s.substr(idx, i);
            if (atoi(tmp.c_str()) > 255) {
                break;
            }
            cur.push_back(tmp);
            restoreIpAddressesCore(s, idx + i, remain - 1);
            cur.pop_back();
            if (i == 1 && s[i] == '0') {
                break;
            }
        }
    }
    void CurToStr() {
        string str;
        for (size_t i = 0; i < cur.size(); i++) {
            str +=  cur[i] + ".";
        }
        str.pop_back();
        results.push_back(str);
    }

    vector<string> cur;
    vector<string> results;
};