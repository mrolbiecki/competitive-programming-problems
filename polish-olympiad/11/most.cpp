#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+2;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int t1, t2, t3;
	int ca, cb, ci;
	
	cin >> n;
	cin >> t1;
	if (n == 1) {
		cin >> t1;
		cout << t1;
		return 0;
	}
	cin >> t2;
	if (n == 2) {
		cout << t2;
		return 0;
	}
	cin >> t3;
	ca = t2;
	cb = t1 + t2 + t3;
	if (n == 3) {
		cout << cb;
		return 0;
	}
	
	for (int i = 4; i <= n; i++) {
		int ti; cin >> ti;
		ci = min(ca + t1 + 2 * t2 + ti, cb + t1 + ti);
		ca = cb;
		cb = ci;
	}
	
	cout << ci;
}
