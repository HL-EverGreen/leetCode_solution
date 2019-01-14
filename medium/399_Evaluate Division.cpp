class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        // method 1
        // map<node1, map<node i, value i>>
        // 0ms, beats 100%
        map<string, map<string, double>> m;
        for (int i = 0; i < values.size(); ++i) {
            string l = equations[i].first;
            const string& r = equations[i].second;
            
            m[l][r] = values[i];
            m[r][l] = 1.0/values[i];
        }

        vector<double> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            const string& l = queries[i].first;
            const string& r = queries[i].second;
            
            if (m.find(l) == m.end()) continue;
            if (m.find(r) == m.end()) continue;
            
            unordered_set<string>       visit;
            queue<pair<string, double>> q;
            
            q.push({l, 1.0});
            
            while (!q.empty()) {
                auto f  = q.front(); q.pop();
                auto mm = m[f.first];
                auto it = mm.find(r);
                
                if (it != mm.end()) {
                    ans[i] = f.second * it->second;
                    break;
                }
                else {
                    visit.insert(f.first);
                    for (it = mm.begin(); it != mm.end(); ++it) {
                        if (visit.find(it->first) == visit.end()) {
                            q.push({it->first, f.second * it->second});
                        }
                    }
                }
            }
        }
        
        return ans; 
    }
    
    // method 2
    // union find
    // 0ms, beats 100%
    /*
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> map;
        vector<double> res;
        for (int i = 0; i < equations.size(); i ++) {
            string s1 = equations[i].first, s2 = equations[i].second;
            if (map.count(s1) == 0 && map.count(s2) == 0) {
                map[s1] = new Node();
                map[s2] = new Node();
                map[s1] -> value = values[i];
                map[s2] -> value = 1;
                map[s1] -> parent = map[s2];
            } else if (map.count(s1) == 0) {
                map[s1] = new Node();
                map[s1] -> value = map[s2] -> value * values[i];
                map[s1] -> parent = map[s2];
            } else if (map.count(s2) == 0) {
                map[s2] = new Node();
                map[s2] -> value = map[s1] -> value / values[i];
                map[s2] -> parent = map[s1];
            } else {
                unionNodes(map[s1], map[s2], values[i], map);
            }
        }

        for (auto query : queries) {
            if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second]))
                res.push_back(-1);
            else
                res.push_back(map[query.first] -> value / map[query.second] -> value);
        }
        return res;
    }
    
private:
    struct Node {
        Node* parent;
        double value = 0.0;
        Node()  {parent = this;}
    };
    
    void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
        double ratio = node2 -> value * num / node1 -> value;
        for (auto it = map.begin(); it != map.end(); it ++)
            if (findParent(it -> second) == parent1)
                it -> second -> value *= ratio;
        parent1 -> parent = parent2;
    }
    
    Node* findParent(Node* node) {
        if (node -> parent == node)
            return node;
        node -> parent = findParent(node -> parent);
        return node -> parent;
    }
    */
};