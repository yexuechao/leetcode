#include<vector>
#include <string>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n <= 0 || k <= 0) {
            return "";
        }

        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        string cur;
        int h = 0;
        int len = 0;
        while(k > 1) {
            int distance = getMul(n - 1 - len);
            if (k > distance) {
                k -= distance;
                h++;
                continue;
            } else {
                cur += to_string(nums[h]);
                nums.erase(nums.begin() + h);
                h = 0;
                len++;
            }
        }
        // 先选定h
        cur += to_string(nums[h]);
        // 把h删除
        nums.erase(nums.begin() + h);
        // 把其他的全部累加起来
        for (int i = 0; i < nums.size(); i++) {
            cur += to_string(nums[i]);
        }

        return cur;
    }

    int getMul(int n) {
        int res = 1;
        for(int i = 2; i <= n; i++)
            res *= i;
        return res;
    }

};