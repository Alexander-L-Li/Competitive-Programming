#include <bits/stdc++.h>
using namespace std;

struct Tuple {
    int x;
    int y;
    int t;
};

bool innocent(int x1,int y1, int t1, Tuple t) {
    long difft = abs(t.t - t1);
    long a = (t.x - x1);
    long b = (t.y - y1);
    long diffdsqr = a *a  + b * b;
    long difftsqr = difft * difft;
    return (diffdsqr > difftsqr);
}


int main() {
    int g,n;
    cin >> g;
    cin >> n;
    vector<Tuple> tuples;
    
    for(int i = 0; i < g; i++) {
        Tuple t;
        cin >> t.x;
        cin >> t.y;
        cin >> t.t;
        tuples.push_back(t);
    }
    sort(tuples.begin(), tuples.end(), [](const Tuple& lhs, const Tuple& rhs) {
      return lhs.t < rhs.t;
    });
    int res = 0;
          
    for(int i = 0; i < n; i++) {
        int cx, cy, ct;
        cin >> cx;
        cin >> cy;
        cin >> ct;
        int l = 0;
        int r = tuples.size()-1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (tuples[mid].t == ct) {
                l = mid;
                r = mid;
                break;
            } else if (tuples[mid].t < ct) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        bool i1 = innocent(cx, cy, ct, tuples[l]);
        bool i2 = false;
        bool i3 = false;
        if (l > 0) {
            i2 = innocent(cx, cy, ct, tuples[l-1]);
        }
        if (l < tuples.size()-1) {
            i3 = innocent(cx, cy, ct, tuples[l+1]);
        }
        if (i1 || i2 || i3) {
            res++;
        }
    }
    cout << res;
}
