class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> res;
        int n=numbers.size();
        for(int i=0;i<n-1;i++) {

            int index = find(i+1, numbers, target-numbers[i]);
            if(index != -1) {
                res.push_back(i+1); res.push_back(index+1);
                return res;
            }
        }

        return res;

    }

    int find(int l, vector<int>& numbers, int val) {

        int h = numbers.size()-1;
        int mid = l + (h-l)/2;
        while(l <=h) {
            mid = l + (h-l)/2;
            if(numbers[mid] == val) return mid;
            else if(numbers[mid] > val) h = mid-1;
            else l = mid+1;
        }

        return -1;
    }
};
