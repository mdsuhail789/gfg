class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        int ans;
        sort(arr.begin(),arr.end());
        
        for(int i =0;i<n-2;i++){
            ans = target- arr[i];
            int start = i+1, end =n-1;
            
            while(start<end){
                if(arr[start]+arr[end]==ans){
                    return true;
                }
                else if(arr[start]+arr[end]>ans){
                    end--;
                }
                else
                start++;
                
            }
            
        }
      return false;
    }
};