#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <stack>
#include <cstring>

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

int oneCnt = 0;

const char ON = '1';
const char OFF = '0';

string board[15];

struct Pos {
    int x;
    int y;
};

struct Triangle {
    bool notAble;
    vector<Pos> pos;
};

struct TryerProps {
    int x;
    int y;
    int size;
};

struct LineAbleProps {
    int y;
    int xst;
    int xsz;
};

bool lineAble(LineAbleProps props) {
    for(int i = props.xst; i <= props.xst + props.xsz - 1; i++)
        if(board[props.y][i] == OFF) return false;
    return true;
}

Triangle tri1(TryerProps props);
Triangle tri2(TryerProps props);
Triangle tri3(TryerProps props);
Triangle tri4(TryerProps props);
Triangle tri5(TryerProps props);
Triangle tri6(TryerProps props);
Triangle tri7(TryerProps props);
Triangle tri8(TryerProps props);

// ㅡㅡㅡㅁㅡㅡㅡ
// ㅡㅡㅁㅁㅁㅡㅡ
// ㅡㅁㅁㅁㅁㅁㅡ
// ㅁㅁㅁㅁㅁㅁㅁ => sz4
// posesGaro
Triangle tri1(TryerProps props) {
    Triangle res;
    res.notAble = false;
    res.pos.push_back({
        props.x,
        props.y + props.size - 1
    });
    res.pos.push_back({
        props.x + props.size - 1,
        props.y
    });
    res.pos.push_back({
        props.x + (props.size - 1) * 2,
        props.y + props.size - 1
    });
    
    if(tri7({
        props.x,
        props.y,
        props.size
    }).notAble) {
        res.notAble = 1;
        return res;
    }
    if(tri6({
        props.x + props.size,
        props.y + 1,
        props.size - 1
    }).notAble) {
        res.notAble = 1;
        return res;
    }
    
    return res;
}

// ㅁㅁㅁㅁㅁㅁㅁ
// ㅡㅁㅁㅁㅁㅁㅡ
// ㅡㅡㅁㅁㅁㅡㅡ => sz 4
// ㅡㅡㅡㅁㅡㅡㅡ
// posesGaro
Triangle tri2(TryerProps props) {
    Triangle res;
    res.notAble = false;
    res.pos.push_back({
        props.x,
        props.y
    });
    res.pos.push_back({
        props.x + (props.size - 1) * 2,
        props.y
    });
    res.pos.push_back({
        props.x + props.size - 1,
        props.y + props.size - 1
    });
    
    if(tri8({
        props.x,
        props.y,
        props.size
    }).notAble) {
        res.notAble = 1;
        return res;
    }
    if(tri5({
        props.x + props.size,
        props.y,
        props.size - 1
    }).notAble) {
        res.notAble = 1;
        return res;
    }
    
    return res;
}

// ㅁㅡㅡ
// ㅁㅁㅡ
// ㅁㅁㅁ => sz 3
// ㅁㅁㅡ
// ㅁㅡㅡ
// posesSaero
Triangle tri3(TryerProps props) {
    Triangle res;
    res.notAble = false;
    res.pos.push_back({
        props.x,
        props.y
    });
    res.pos.push_back({
        props.x + props.size - 1,
        props.y + props.size - 1
    });
    res.pos.push_back({
        props.x,
        props.y + (props.size - 1) * 2
    });
    
    if(tri6({
        props.x,
        props.y,
        props.size
    }).notAble) {
        res.notAble = 1;
        return res;
    }
    if(tri5({
        props.x,
        props.y + props.size,
        props.size - 1
    }).notAble) {
        res.notAble = 1;
        return res;
    }
    
    return res;
}

// ㅡㅡㅁ
// ㅡㅁㅁ
// ㅁㅁㅁ => sz 3
// ㅡㅁㅁ
// ㅡㅡㅁ
// posesSaero
Triangle tri4(TryerProps props) {
    Triangle res;
    res.notAble = false;
    res.pos.push_back({
        props.x + props.size - 1,
        props.y
    });
    res.pos.push_back({
        props.x,
        props.y + props.size - 1
    });
    res.pos.push_back({
        props.x + props.size - 1,
        props.y + (props.size - 1) * 2
    });
    
    if(tri7({
        props.x,
        props.y,
        props.size
    }).notAble) {
        res.notAble = 1;
        return res;
    }
    if(tri8({
        props.x + 1,
        props.y + props.size,
        props.size - 1
    }).notAble) {
        res.notAble = 1;
        return res;
    }
    
    return res;
}

// ㅁㅁㅁ
// ㅁㅁㅡ
// ㅁㅡㅡ
// posesBySz
Triangle tri5(TryerProps props) {
    Triangle res;
    res.notAble = false;
    res.pos.push_back({
        props.x,
        props.y
    });
    res.pos.push_back({
        props.x + props.size - 1,
        props.y
    });
    res.pos.push_back({
        props.x,
        props.y + props.size - 1
    });
    
    // Y ADDER
    for(int i = 0;i < props.size;i++)
        if(!lineAble({
            props.y + i,
            props.x,
            props.size - i
        })) {
            res.notAble = true;
            break;
        }
    
    return res;
}

// ㅁㅡㅡ
// ㅁㅁㅡ
// ㅁㅁㅁ
// posesBySz
Triangle tri6(TryerProps props) {
    Triangle res;
    res.notAble = false;
    res.pos.push_back({
        props.x,
        props.y
    });
    res.pos.push_back({
        props.x,
        props.y + props.size - 1
    });
    res.pos.push_back({
        props.x + props.size - 1,
        props.y + props.size - 1
    });
    
    // Y ADDER
    for(int i = 0;i < props.size;i++)
        if(!lineAble({
            props.y + i,
            props.x,
            i + 1
        })) {
            res.notAble = true;
            break;
        }
    
    return res;
}

// ㅡㅡㅁ
// ㅡㅁㅁ
// ㅁㅁㅁ
// posesBySz
Triangle tri7(TryerProps props) {
    Triangle res;
    res.notAble = false;
    res.pos.push_back({
        props.x + props.size - 1,
        props.y
    });
    res.pos.push_back({
        props.x,
        props.y + props.size - 1
    });
    res.pos.push_back({
        props.x + props.size - 1,
        props.y + props.size - 1
    });
    
    // Y ADDER
    for(int i = 0;
        i < props.size;
        i++)
        if(!lineAble({
            props.y + i,
            props.x + props.size - 1 - i,
            i + 1
        })) {
            res.notAble = true;
            break;
        }
    
    return res;
}

// ㅁㅁㅁ
// ㅡㅁㅁ
// ㅡㅡㅁ
// posesBySz
Triangle tri8(TryerProps props) {
    Triangle res;
    res.notAble = false;
    res.pos.push_back({
        props.x,
        props.y
    });
    res.pos.push_back({
        props.x + props.size - 1,
        props.y
    });
    res.pos.push_back({
        props.x + props.size - 1,
        props.y + props.size - 1
    });
    
    // Y ADDER
    for(int i = 0;i < props.size;i++)
        if(!lineAble({
            props.y + i,
            props.x + i,
            props.size - i
        })) {
            res.notAble = true;
            break;
        }
    
    return res;
}

// maxSZ ; 10
vector<Pos> posesBySz(int sz) {
    vector<Pos> res;
    for(int i = 1; i + sz - 1 <= 10; i++)
        for(int j = 1; j + sz - 1 <= 10; j++)
            res.push_back({i, j});
    return res;
}

// maxSZ ; 5
vector<Pos> posesGaro(int sz) {
    vector<Pos> res;
    for(int i = 1; i+(sz-1)*2 <= 10; i++)
        for(int j = 1; j + sz - 1 <= 10; j++)
            res.push_back({i, j});
    return res;
}

// maxSZ ; 5
vector<Pos> posesSaero(int sz) {
    vector<Pos> res;
    for(int j = 1; j + sz - 1 <= 10; j++)
        for(int i = 1; i+(sz-1)*2 <= 10; i++)
            res.push_back({j, i});
    return res;
}

int rep(int x) {
    int a = 0;
    for(int i = 1; i <= x; i++) a += i;
    return a;
}

Triangle tryAll(TryerProps props) {
    if(rep(props.size) != oneCnt) return {true, {}};
    Triangle x = tri5(props);
    if(!x.notAble) return x;
    x = tri6(props);
    if(!x.notAble) return x;
    x = tri7(props);
    if(!x.notAble) return x;
    x = tri8(props);
    return x;
}

Triangle tryAllSaero(TryerProps props) {
    
    if(rep(props.size) + rep(props.size - 1) != oneCnt) return {true, {}};
    Triangle x = tri3(props);
    if(!x.notAble) return x;
    x = tri4(props);
    return x;
}

Triangle tryAllGaro(TryerProps props) {
    if(rep(props.size) + rep(props.size - 1) != oneCnt) return {true, {}};
    Triangle x = tri1(props);
    if(!x.notAble) return x;
    x = tri2(props);
    return x;
}

string pos(Pos a) {
    return to_string(a.x) + "," + to_string(a.y);
}

void printTri(Triangle t) {
    sort(t.pos.begin(), t.pos.end(), [](Pos a, Pos b) {
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });
    for(int i = 0;i < t.pos.size();i++) cout << t.pos[i].y << " " << t.pos[i].x << "\n";
}

int main()
{
    for(int i = 1;i <= 10;i++) {
        cin >> board[i];
        board[i] = "0" + board[i];
        for(int j = 0;j < board[i].size();j++)
            if(board[i][j] == ON) oneCnt++;
    }
    
    // cout << "ONE" << oneCnt << "\n";
    
    bool flag = true;
    Triangle ans;
    int anssz = 0;
    for(int sz = 5; sz >= 1 && flag; sz--)
        for(Pos pos : posesGaro(sz)) {
            Triangle t = tryAllGaro({
                pos.x,
                pos.y,
                sz
            });
            if(!t.notAble) {
                if(ans.notAble || anssz < sz) {
                    ans = t;
                    anssz = sz;
                }
                flag = false;
                break;
            }
        }
    flag = true;
    for(int sz = 5; sz >= 1 && flag; sz--)
        for(Pos pos : posesSaero(sz)) {
            Triangle t = tryAllSaero({
                pos.x,
                pos.y,
                sz
            });
            if(!t.notAble) {
                if(ans.notAble || anssz < sz) {
                    ans = t;
                    anssz = sz;
                }
                flag = false;
                break;
            }
        }
    flag = true;
    for(int sz = 10; sz >= 1 && flag; sz--)
        for(Pos pos : posesBySz(sz)) {
            Triangle t = tryAll({
                pos.x,
                pos.y,
                sz
            });
            if(!t.notAble) {
                if(ans.notAble || anssz < sz) {
                    ans = t;
                    anssz = sz;
                }
                flag = false;
                break;
            }
        }
    
    if(ans.notAble || anssz == 0) cout << "0";
    else printTri(ans);
}
