class Solution {
public:
    int findPages(vector<int> &arr, int M) {
        int N = arr.size();
        if (M > N) 
        return -1;

        int start = 0, end = 0, ans ;
        

        for (int i = 0; i < N; i++) {
            start = max(start, arr[i]);  
            end += arr[i];               
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int pages = 0, count = 1;  

            // Check if mid can be the answer
            for (int i = 0; i < N; i++) {
                pages += arr[i];
                if (pages > mid) {
                    count++;
                    pages = arr[i];
                }
            }

            if (count <= M) {  
                ans = mid;
                end = mid - 1;
            } else {  
                start = mid + 1;
            }
        }
        return ans;
    }
};
