#include<string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return string("/");
        }
        vector<string> dir = split(path, '/');
        stack<string> stk1;
        for (int i = 0; i < dir.size(); i++) {
            if (dir[i] == "..") {
                if (!stk1.empty()) {
                    stk1.pop();
                }
            } else if (!dir[i].empty() && dir[i] != ".") {
                stk1.push(dir[i]);
            }
        }
        if (stk1.empty()) {
            return "/";
        }
        string result;
        while(!stk1.empty()) {
            string tmp = "/";
            tmp += stk1.top();
            stk1.pop();
            result = tmp + result;
        }

        return result;
    }

    std::vector<std::string> split(const std::string &s, char delim) {
        std::stringstream ss(s);
        std::string item;
        std::vector<std::string> elems;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
            // elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
        }
        return elems;
    }

};