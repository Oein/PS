#include <iostream>
#include <map>
#include <string>
#include<algorithm>
#include <vector>

using namespace std;

class Node {
public:
	map<char, Node*>child; //자식Node
	char data; //자신의 데이터
	int cnt = 0; //자식 개수

	Node(char data) {
		//생성자
		this->data = data;
		this->cnt = 0;
	}

	/* Node& get(string key) {
		Node* cursor = this; //커서 생성
		for (char c : key) { //한칸씩 반복
			if (cursor->child.find(c) == cursor->child.end()) {
				//not found
				cursor->child.insert(pair<char, Node*>(c, new Node(c))); //새로 만들고 insert
			}
			cursor = cursor->child[c]; //커서 이동
		}
		return *cursor; //리턴
	} */

	bool append(string key) {
		this->cnt++; //cnt를 올린다.
		bool returnData = true; //리턴할 대이터를 선언한다.

		if (key.length() == 0)return true; //끝나면 종료한다.
		if (this->child.find(key[0]) == this->child.end()) { //없는지 확인한다.
			//not found
			Node* child_temp = new Node(key[0]); //새로운 Node를 만든다

			this->child.insert(pair<char, Node*>(key[0], child_temp)); //insert한다.
		}
		
		bool next_child = this->child[key[0]]->append(key.substr(1));//나머지 애들도 반복한다.
		if (next_child == false) returnData = false; //나머지 애들이 false를 리턴하면 자기자신도 false를 리턴한다.
		int tempCnt = this->cnt; //cnt를 건드릴수 없으니까 복사본을 만든다.

		for (int i = '0'; i <= '9'; i++) { //0 ~ 9 까지 반복한다.
			if (child.find(i) != child.end()) { //현재 검사중인 child가 있으면 실행
				tempCnt -= child[i]->cnt; //검사중인 child의 cnt만큼 뺀다.
			}
		}

		if (tempCnt != 0) { //반복했을때 남는 데이터(여기서 끝난 데이터)가 있으면 flase를 리턴한다.
			returnData = false;
		}
		return returnData; //리턴
	}
};

int comp(int a, int b) {
	if (a < b) {
		return -1;
	}
	else if (a > b) {
		return 1;
	}

	return 0;
}

int main() {
	int t = 0;
	cin >> t; //캐이스 수 입력
	for (int first = 0; first < t; first++) { // 캐이스 만큼 반복
		bool is_ok = true;
		int n = 0;
		cin >> n; //전화번호 수 입력
		Node Number_Book = *new Node(' '); //전화번호부 생성
		vector<string> Numbers;
		for (int i = 0; i < n; i++) { // 전화번호 수 만큼 반복
			string inputed_data = ""; //temp
			cin >> inputed_data; //입력
			Numbers.push_back(inputed_data);
		}

		sort(Numbers.begin(), Numbers.end());

		for (string s : Numbers) { //한칸씩 반복
			if (Number_Book.append(s) != true || is_ok == false) { //push 푸시 했을때 일관성이 없으면 is_ok를 false로 바꾼다.
				is_ok = false; //is_ok를 false로 바꾼다.
			}
		}

		if (is_ok == true) cout << "YES\n"; // is_ok가 true면 YES\n 을 출력한다.
		else cout << "NO\n"; //아니면 NO\n을 출력한다.
	}
}