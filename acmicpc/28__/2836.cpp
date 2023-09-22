#include <bits/stdc++.h>

using namespace std;

bool detail = false;

struct Person {
	int f = 0; // from
	int t = 0; // to
	bool did = false;
};


bool sort_func(Person a, Person b) {
	return a.f < b.f;
}

int main() {
	int count_of_people = 0;
	int end = 0;
	cin >> count_of_people;
	cin >> end;

	vector<Person> people;

	long long int need = end;

	for (int i = 0; i < count_of_people; i++) {
		Person person;
		cin >> person.t >> person.f;

		if (person.t > person.f) {
			people.push_back(person);
		}
	}

	sort(people.begin(), people.end(), sort_func);

	int last_end_idx = 0;
	int last_start_idx = 0;
	long long int add = 0;
	for (int i = 0; i < people.size(); i++) {
		Person now = people[i];
		if (detail) cout << "i : " << i << "   people.size() : " << people.size() << "\n";
		if (detail) cout << "Start : " << now.f << "  End : " << now.t << "\n";
		if (detail) cout << "last_end_idx : " << last_end_idx << "  last_start_idx : " << last_start_idx << "\n";

		if (now.f >= last_start_idx && now.f <= last_end_idx) { // 전에 꺼랑 겹치는가?
			if (detail) cout << "겹친다 \n";
			if (last_end_idx < now.t) {
				last_end_idx = now.t; // 끝 지점 늘리기
			}
		}
		else { // ㄴㄴ
			if (detail) cout << "안 겹침  Add * 2 : " << add * 2 << "\n";
			add = last_end_idx - last_start_idx; // 이동 거리
			need += add * 2; // 움직이는 거 추가
			last_end_idx = now.t; // 처음
			last_start_idx = now.f; // 끝
		}

		if (detail) cout << "\n\n";
	}

	add = last_end_idx - last_start_idx;
	need += add * 2;

	cout << need;
}