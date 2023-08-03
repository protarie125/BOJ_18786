#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto px = vector<ll>(n);
	auto py = vector<ll>(n);

	for (auto i = 0; i < n; ++i) {
		cin >> px[i] >> py[i];
	}

	auto ans = ll{ 0 };
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}

			for (auto k = 0; k < n; ++k) {
				if (i == k || j == k) {
					continue;
				}

				if (px[i] == px[j] && py[i] == py[k]) {
					auto area = abs(py[i] - py[j]) * abs(px[i] - px[k]);
					ans = max(ans, area);
				}
			}
		}
	}

	cout << ans;

	return 0;
}