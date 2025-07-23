class Solution {
  public:
    int minTime(vector<int>& arr, int M) {
        int N = arr.size();
       // if (M > N) return -1;

        long long start = 0, end = 0, ans ;

        for (int i = 0; i < N; i++) {
            start = max(start, (long long)arr[i]);
            end += arr[i];
        }

        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long time = 0;
            int count = 1;

            for (int i = 0; i < N; i++) {
                time += arr[i];
                if (time > mid) {
                    count++;
                    time = arr[i];
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
