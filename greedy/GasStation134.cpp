class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || gas.size() != cost.size()) {
            return -1;
        }

        int cur_tank = 0;
        int total_tank = 0;
        int station = 0;
        for (int i = 0; i < gas.size(); i++) {
            cur_tank += gas[i] - cost[i];
            total_tank += gas[i] - cost[i];
            if (cur_tank < 0) {
                cur_tank = 0;
                station = i + 1;
            }
        }
        if (total_tank >= 0) {
            return station;
        }
        return -1;
    }
};