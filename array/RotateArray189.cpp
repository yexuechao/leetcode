class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return ;
        }
        int size = nums.size();
        int rotate = k % size;
        if (rotate == 0) {
            return ;
        }
        vector<int>::iterator itr = nums.end();
        while(rotate > 0) {
            itr--;
            rotate--;
        }
        reverse(nums.begin(), itr);
        reverse(itr, nums.end());
        reverse(nums.begin(), nums.end());
    }
};