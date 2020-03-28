#include "../define.h"
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        unordered_set<string> used_word;
        int step = 1;
        queue<string> que;
        que.push(beginWord);
        while(!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                string word = que.front();
                for (int j = 0; j < word.size(); j++) {
                    for (char k = 'a'; k <= 'z'; k++) {
                        if (word[j] == k) {
                            continue;
                        }
                        string cur_word = word;
                        cur_word[j] = k;
                        if (word_set.find(cur_word) == word_set.end() || used_word.find(cur_word) != used_word.end()) {
                            continue;
                        }
                        if (cur_word == endWord) {
                            return step + 1;
                        }
                        used_word.insert(cur_word);
                        que.push(cur_word);
                    }
                }
                que.pop();
            }
            step++;
        }

        return 0;
    }
};