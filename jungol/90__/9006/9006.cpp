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
#define PROBLEM 9006
#define TIMEOUT 1000LL
#define SOLUTION_FUNCTION main_

using namespace std;

int main_() {
    cout << "수를 출력할 때는 따옴표를 생략합니다.\n123\n6.500000";
    return 0;
}

#ifdef ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    main_();
    return 0;
}
#endif
