#include <iostream>
#include <set>

int main() {
	// 여기에 코드를 작성해주세요.
	uint64_t n, t;
	std::cin >> n >> t;

	std::set<uint64_t> s;
	while (n--) {
		uint64_t a, b;
		std::cin >> a >> b;

		uint64_t target = a + b * t;

                // 나보다 앞지른 사람만 모두 제거합니다. 같은 그룹으로 포함시키기 위해서
		while (1) {
			auto it = s.lower_bound(target);
			if (it == s.end())
				break;

			s.erase(it);
		}

		s.emplace(target); // 그룹으로 등록합니다.
	}

	std::cout << s.size(); // 그룹 사이즈 수

	return 0;
}