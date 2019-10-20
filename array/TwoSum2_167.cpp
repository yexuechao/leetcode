class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() <= 1) {
            return vector<int>();
        }
        int head = 0;
        int tail = numbers.size() - 1;
        vector<int> result;
        while(head < tail){
            if (numbers[head] + numbers[tail] == target) {
                result.push_back(head + 1);
                result.push_back(tail + 1);
                return result;
            } else if (numbers[head] + numbers[tail] < target) {
                head++;
            } else {
                tail--;
            }
        }
        return result;
    }
};