#include <vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        int count1 = 0;
        int num1 = nums[0];
        int count2 = 0;
        int num2 = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num1) {
                count1++;
            } else if (nums[i] == num2) {
                count2++;
            } else {
                if (count1 == 0) {
                    num1 = nums[i];
                    count1 = 1;
                    continue;
                }
                if (count2 == 0) {
                    num2 = nums[i];
                    count2 = 1;
                    continue;
                }
                // 两个都不为0
                count1--;
                count2--;
            }
        }
        // 还要遍历一遍确认 > n/3
        int real_count1 = 0;
        int real_count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num1) {
                real_count1++;
            } else if (nums[i] == num2) {
                real_count2++;
            }
        }
        vector<int> result;
        if (real_count1 > nums.size() / 3) {
            result.push_back(num1);
        }
        if (real_count2 > nums.size() / 3) {
            result.push_back(num2);
        }
        return result;
    }
};