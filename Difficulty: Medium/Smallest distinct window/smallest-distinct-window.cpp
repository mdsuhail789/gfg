class Solution {
public:
    int findSubString(string& str) {
        // code here
        vector<int> count(256, 0);   // 26 ki jagah 256 (ASCII chars ke liye)
        int diff = 0;
        int first = 0, second = 0, len = str.length();

        // pehle total distinct characters gin lo (diff me store)
        while (first < (int)str.size()) {
            unsigned char ch = str[first];
            if (count[ch] == 0) diff++;
            count[ch]++;
            first++;
        }

        // count reset + pointers reset
        fill(count.begin(), count.end(), 0);
        first = 0;
        second = 0;

        // sliding window
        while (second < (int)str.size()) {
            unsigned char ch = str[second];
            if (count[ch] == 0) diff--;       // ek naya required char cover hua
            count[ch]++;
            second++;

            // jab tak saare distinct chars window me hain (diff == 0), shrink karo
            while (diff == 0) {
                len = min(len, second - first);

                unsigned char left = str[first];
                count[left]--;
                if (count[left] == 0) diff++; // ek char nikal gaya, ab missing
                first++;
            }
        }

        return len;
    }
};
