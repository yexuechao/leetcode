class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> results;
        if (input.empty()) {
            return results;
        }
        return diffWaysToComputeCore(input);
    }

    vector<int> diffWaysToComputeCore(string input) {
        vector<int> results;
        if (input.find("+") == string::npos &&\
            input.find("-") == string::npos &&\
            input.find("*") == string::npos) {
            results.push_back(atoi(input.c_str()));
            return results;
        }
        for (size_t i = 0; i < input.size(); i++) {
            if (input[i] == '+' ||\
                input[i] == '-' ||\
                input[i] == '*') {
                vector<int> pre_result = diffWaysToComputeCore(input.substr(0, i));
                vector<int> next_result = diffWaysToComputeCore(input.substr(i + 1));
                for (size_t j = 0; j < pre_result.size(); j++) {
                    for (size_t k = 0; k < next_result.size(); k++) {
                        if (input[i] == '+') {
                            results.push_back(pre_result[j] + next_result[k]);
                        } else if (input[i] == '-') {
                            results.push_back(pre_result[j] - next_result[k]);
                        } else if (input[i] == '*') {
                            results.push_back(pre_result[j] * next_result[k]);
                        }
                    }
                }
            }
        }
        return results;
    }
};