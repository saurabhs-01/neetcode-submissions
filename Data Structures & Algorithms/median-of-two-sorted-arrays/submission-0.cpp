class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> arr;
        int i=0; int j=0; int n1= nums1.size(); int n2= nums2.size();
        while(i<n1 && j<n2) {
            if(nums1[i] <= nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n1) {
            arr.push_back(nums1[i]); i++;
        }
        while(j<n2) {
            arr.push_back(nums2[j]); j++;
        }

        if((n1+n2)%2 !=0) return (double) arr[(n1+n2)/2];
        return (double) (arr[(n1+n2)/2] + arr[(n1+n2)/2-1])/2;
    }
};
