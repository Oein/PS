#include<bits/stdc++.h>

using namespace std;
int color[5001];


int main() {
	int x, y; // x좌표와 y색깔
	int N = 0; // 점의 갯수

	cin >> N;
	vector<vector<int>> arr(N + 1); // 2차원 배열
	int distance = 0; // 거리의 합

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		arr[y].push_back(x); // 색깔별로 점들 분류하기
		color[y]++; // 같은 색의 점들이 각각 몇개 있는지 표시하기 위한 배열
	}

	for (int i = 1; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end()); // 색깔별로 2차원 배열 정렬하기 
	}

	for (int i = 1; i <= N; i++) {
		if (arr[i].size() == 0) continue; // 해당 색깔의 점이 0이라면 건너뛰기


		for (int j = 0; j < color[i]; j++) {
			if (j == 0) distance += arr[i][1] - arr[i][0]; // 맨 처음부분 연산
			else if (j == color[i] - 1) distance += arr[i][color[i] - 1] - arr[i][color[i] - 2]; // 맨 끝부분 연산
			else {
				int a = arr[i][j - 1];
				int b = arr[i][j + 1];

				distance += min(arr[i][j] - a, b - arr[i][j]); //양 옆의 거리들중 작은 값 더하기
			}
		}


	}
	cout << distance;
}