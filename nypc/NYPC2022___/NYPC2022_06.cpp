#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

typedef uint32_t Hash;

/*
    This hash function is from http://www.azillionmonkeys.com/qed/hash.html
 */
#include <stdint.h> /* Replace with <stdint.h> if appropriate */
#include <string>
using namespace std;
#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) || defined(_MSC_VER) || defined(__BORLANDC__) || defined(__TURBOC__)
#define get16bits(d) (*((const uint16_t *)(d)))
#endif

#if !defined(get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8) + (uint32_t)(((const uint8_t *)(d))[0]))
#endif

uint32_t SuperFastHash(const char *data, int len)
{
    uint32_t hash = len, tmp;
    int rem;

    if (len <= 0 || data == NULL)
        return 0;

    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (; len > 0; len--)
    {
        hash += get16bits(data);
        tmp = (get16bits(data + 2) << 11) ^ hash;
        hash = (hash << 16) ^ tmp;
        data += 2 * sizeof(uint16_t);
        hash += hash >> 11;
    }

    /* Handle end cases */
    switch (rem)
    {
    case 3:
        hash += get16bits(data);
        hash ^= hash << 16;
        hash ^= ((signed char)data[sizeof(uint16_t)]) << 18;
        hash += hash >> 11;
        break;
    case 2:
        hash += get16bits(data);
        hash ^= hash << 11;
        hash += hash >> 17;
        break;
    case 1:
        hash += (signed char)*data;
        hash ^= hash << 10;
        hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

/*
    Make easy for string hashing
 */
uint32_t SuperFastHash(string str)
{
    return SuperFastHash(str.c_str(), str.size());
}
/************* Hash Function Done *************/

enum PartID
{
    Body = 0,
    Wheel = 1,
    Handle = 2,
    Engine = 3,
    Booster = 4,
};

int printOrder[] = {0, 2, 1, 3, 4};

struct Part
{
    Hash bounusHash;
    ull score;
};

PartID GetPartID(string str)
{
    if (str[0] == 'H')
        return PartID::Handle;
    else if (str[0] == 'W')
        return PartID::Wheel;
    else if (str[0] == 'E')
        return PartID::Engine;
    else if (str[2] == 'd')
        return PartID::Body;
    else if (str[2] == 'o')
        return PartID::Booster;
    return PartID::Body;
}

// use for output
unordered_map<Hash, string> partName;
// use for dfs
vector<Part> parts[6];

int engineIdx = -1;
int boosterIdx = -1;
ull ebScore = 0;

bool fd = 0;
ull ans = 0;
ull gonnanFind = 0;

ull Abs(ull a, ull b)
{
    return a > b ? a - b : b - a;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string partType_str, bonusName;
        ull score;
        cin >> partType_str >> bonusName >> score;

        Hash hashed_bounusName = SuperFastHash(bonusName);
        PartID partType = GetPartID(partType_str);

        parts[partType].push_back({hashed_bounusName, score});

        partName.insert(make_pair(hashed_bounusName, bonusName));
    }
}