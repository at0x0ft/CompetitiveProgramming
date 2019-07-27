#include <bits/stdc++.h>
using namespace std;

int depth(string line) {
    int ret = 0;
    while(line[ret] == '.') ret++;
    return ret;
}

int main() {
    while(true) {
        int n; cin >> n;
        if (n == 0) break;
        vector< pair<int, string> > posts;
        int max_d = 0;
        for (int i = 0; i < n; i++) {
            string line; cin >> line;
            int d = depth(line);
            if (d > max_d) max_d = d;
            posts.push_back(make_pair(d, line));
        }
        vector<int> bars(max_d + 1);
        for (int i = n-1; i >= 1; i--) {
            auto& post = posts[i];
            if (post.first-1 >= 0) bars[post.first-1] = 0;
            for (int i = 0; i < post.first-1; i++) {
                if (bars[i]) post.second[i] = '|';
                else         post.second[i] = ' ';

            }
            if (post.first-1 >= 0) {
                post.second[post.first-1] = '+';
                if (post.first < posts[i-1].first) bars[post.first-1] = 1;
            }
        }
        for (int i = 0; i < n; i++) cout << posts[i].second << endl;
    }
    return 0;
}
