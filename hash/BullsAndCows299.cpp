class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() != guess.size()) {
            return string();
        }
        // Bulls
        int bulls = 0;
        int secret_count[10] = {0};
        int guess_count[10] = {0};

        for (size_t i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            secret_count[s]++;
            guess_count[g]++;
        }
        int distance = 0;
        for (size_t i = 0; i < 10; i++) {
            distance += min(secret_count[i], guess_count[i]);
        }
        int cows = distance - bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};