#include <bits/stdc++.h>

#define ONLINE_JUDGE
#if !defined (ONLINE_JUDGE)
	#include "debug.hpp"
#else
	#define debug(...) // なんでもいい...
#endif

template <typename T, typename Compare = std::greater<T>>
using BinaryHeap = std::priority_queue<T, std::vector<T>, Compare>;
template <typename T>
using Stack = std::stack<T, std::vector<T>>;

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
using db = double;
using ld = long double;

template <typename T> constexpr T inf = std::numeric_limits<T>::max() / 2;

using namespace std;

void Main() {
	int n, m;
	cin >> n >> m;
	multiset<i64> st;
	i64 ans = 0;	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		st.emplace(x);
		ans += x;
	}
	vector<pair<i64,i64>> b(m);
	for (int i = 0; i < m; i ++) {
		i64 x;
		cin >> x;
		b[i].second = x;
	}
	for (int i = 0; i < m; i ++) {
		i64 x;
		cin >> x;
		b[i].first = x;
	}
	sort(b.begin(), b.end());
	while (!b.empty()) {
		auto [d, l] = b.back();
		b.pop_back();
		auto it = st.lower_bound(l);
		if (it == st.end()) {
			continue;
		} else {
			ans -= d;
			st.extract(it);
		}
	}
	cout << ans << '\n';
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int test = 1;
	//cin >> test;

	for (int rp = 1; test --> 0; rp ++) {
		debug(rp);
		Main();
	}
}
