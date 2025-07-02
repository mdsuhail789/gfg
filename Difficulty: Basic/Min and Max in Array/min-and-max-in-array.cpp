// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        
        int maxs =INT_MIN;
        int mins =INT_MAX;
        
        for(int val:arr){
            maxs =max(val,maxs);
            mins =min(val, mins);
        }
        
        return {mins,maxs};
        
    }
};