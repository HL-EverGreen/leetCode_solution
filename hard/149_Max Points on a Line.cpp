/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct pairhash{
    template <typename T, typename U>
    size_t operator()(const pair<T, U>& x) const {
        return hash<T>()(x.first) ^ hash<U>()(x.second);
    }
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        // geometry
        // time complexity: O(n^2), space complexity: O(n)
        // 12ms, beats 98.78%
        
        // main idea:
        // For each point, calculate all lines' slope consisted of this point and one other point.
        // 经过一点且斜率相同的线就是同一直线
        // In the mean time, record overlapped points and vertical points. 算出经过该点的直线上最多的点数，记为Num_p
        // 比较所有Num_p，即为所有直线中最多的点数
        
        if(points.size() < 2) return points.size();
        int res = 0, size = points.size();
        
        for(int i = 0; i < size - 1; i++) {
            int cur_x = points[i].x, cur_y = points[i].y;
            int overlap = 0, vertical = 0, cur_max = 0;
            unordered_map<pair<int, int>, int, pairhash> lines;     // use pair as unordered_map's key, so need to provide hash function
            
            for(int j = i + 1; j < size; j++) {
                int new_x = points[j].x, new_y = points[j].y;
                if(cur_x == new_x && cur_y == new_y) {
                    overlap++;
                    continue;
                } else if(cur_x == new_x) vertical++;
                else {
                    int a = new_x - cur_x, b = new_y - cur_y, gcd = computeGCD(a, b);
                    a = a / gcd;
                    b = b / gcd;
                    cur_max = max(cur_max, ++lines[make_pair(a, b)]);
                }
                cur_max = max(cur_max, vertical);
            }
            
            res = max(res, cur_max + overlap + 1);
        }
        return res;
    }
    
    // find greatest common divisor
    int computeGCD(int a, int b) {
        if(b == 0) return a;
        else return computeGCD(b, a % b);
    }
};