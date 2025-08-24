// author: Marcin Rolbiecki
// date: 2025-02-19
// problem: https://szkopul.edu.pl/c/plo155/problemset/problem/WXorPFSPZwmWfJWy1GSuJ9QD/site/?key=statement

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <vector <int>> ans;
string s;

deque<int> l, window, r;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cin >> s;
	s = "#" + s;
	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		window.push_back(i);
		sum += (s[i] == 'b' ? 1 : -k);
		
		if ((int)window.size() > k + 1) {
			l.push_back(window.front());
			sum -= (s[window.front()] == 'b' ? 1 : -k);
			window.pop_front();
		}
		
		if (sum == 0) {
			vector<int> res;
			while (!window.empty()) {
				res.push_back(window.front());
				window.pop_front();
			}
			
			ans.push_back(res);
			
			while ((int)window.size() < k + 1 && !l.empty()) {
				window.push_front(l.back());
				sum += (s[l.back()] == 'b' ? 1 : -k);
				l.pop_back();
			}
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	for (auto vec : ans) {
		for (int v : vec)
			cout << v << ' ';
		cout << '\n';
	}

  return 0;
}
