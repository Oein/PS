// main.cpp
#include <future>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <chrono>
#include <vector>
#include <sys/resource.h>
#include <sys/time.h>
// solution.cpp
#include <iostream>
// config defines
#define PROBLEM 9003
#define TIMEOUT 1000LL
#define SOLUTION_FUNCTION main_

using namespace std;

int main_() {
    cout << "세 번째 프로그램입니다.\n줄을 바꾸어 출력합니다.\n여기까지 출력하고\n줄을 바꿉니다.";
    return 0;
}

#ifdef ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    main_();
    return 0;
}
#endif
