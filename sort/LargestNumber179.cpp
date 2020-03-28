#include <vector>
using namespace std;
class Solution {
public:
    static bool cmp(int n1, int n2) {
        string str1 = to_string(n1) + to_string(n2);
        string str2 = to_string(n2) + to_string(n1);
        if (str1 >= str2) {
            return true;
        }
        return false;
        // return (str1 >= str2);
    }
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) {
            // 如果最大的是0
            return "";
        }
        string result;
        for (int i = 0; i < nums.size(); i++) {
            result += to_string(nums[i]);
        }

        // 去除前导0
        return result;
    }
};