class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
         int n = gas.size();

        bool started = false;
        int total = 0;
        int totalE = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < (i + n); j++) {

                total += (gas[j % n] - cost[j % n]);
                totalE++;
                if (total < 0) {
                    total = 0;
                    i=j;
                    totalE = 0;
                    break;
                }
                if(totalE == n) return i;
            }
        }

        return -1;

    }
};
