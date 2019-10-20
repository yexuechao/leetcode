class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) {
            return vector<string>();
        }
        unordered_map<string, int> u_map;
        vector<string> results;
        for (size_t i = 0; i < s.size() - 9; i++) {
            string str = s.substr(i, 10);
            u_map[str]++;
            if (u_map[str] == 2) {
                results.push_back(str);
            }
        }
        return results;
    }
};