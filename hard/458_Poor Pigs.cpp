class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // math
        // 0ms, beats 100%
        
        // Main idea:
        // If with 1 pig, within minutesToTest and minutesToDie, number of test
        // can be finished is (minutesToTest / minutesToDie), so we can find poison
        // in (minutesToTest / minutesToDie) + 1 bucket.
        // If with 2 pig, we can find ((minutesToTest / minutesToDie) + 1)^2 buckets since we can let one pig try by row and another pig try by column.. If pig one dies in row i and pig 2 dies in row j, the poison is at (i, j) bucket.
        // So the maximum buckets we can do with m pig, s time to die and n test time is ((n / s) + 1)^m
        
        int pig = 0;
        while(pow((minutesToTest / minutesToDie) + 1, pig) < buckets) {
            pig++;
        }
        return pig;
    }
};