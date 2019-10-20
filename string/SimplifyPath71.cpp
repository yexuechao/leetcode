#include<string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return string("/");
        }
        string ori_path = path;
        // ../
        // ./
        // //
        string result = "/";
        // 把左边的/ 全部去掉
        string::size_type pos = path.find_first_not_of('/');
        if (pos == string::npos) {
            return result;
        }
        path = path.substr(pos);
        for (size_t i = 0; i < path.size(); i++) {
            if (path[i] == '/'){
                if (result.back() == '/') {
                    continue;
                } else {
                    result += path[i];
                    continue;
                }
            } else if (path[i] == '.') {
                if (i + 1 < path.size()) {
                    if (path[i + 1] == '/') {
                        i++;
                        continue;
                    } else if (path[i + 1] == '.') {
                        // 有种非法的情况，3个点
                        if (i + 2 < path.size()) {
                            if (path[i + 2] != '/') {
                                // 是个文件名，全部一起收了
                                while(path[i] == '.') {
                                    i++;
                                    result += ".";
                                }
                                i--;
                                continue;
                            }
                        }
                        result = DelDot(result);
                        i += 2;
                    } else if (isalpha(path[i + 1])) {
                        result += path[i];
                        continue;
                    }
                } else {
                    continue;
                }
            } else {
                result += path[i];
                continue;
            }
        }
        // 去掉最后的 /
        if(result.back() == '/' && result.size() != 1) {
            result.pop_back();
        }
        return result;
    }
    string DelDot(string s) {
        if (s.empty()) {
            return s;
        }
        // 先去掉最后一个 /
        if(s.back() == '/') {
            s.pop_back();
        }
        // 获取最后一个 / 的位置
        string::size_type pos = s.find_last_of('/');
        if (pos == string::npos) {
            return "/";
        }
        string str = s.substr(0, pos);
        // return (str.empty() ? "/" : str + "/");
        return str + "/";
    }
};