#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class CVector
{
public:
    vector<T> vec;
    unsigned long rotate = 0;

    CVector()
    {
    }
    CVector(int size)
    {
        vec.reserve(size);
    }
    CVector(size_t size)
    {
        vec.reserve(size);
    }
    CVector(size_t size, T v)
    {
        vec.reserve(size);
        for (size_t i = 0; i < size; i++)
        {
            vec.push_back(v);
        }
    }

    void push(T v)
    {
        vec.push_back(v);
    }

    void push_back(T v)
    {
        vec.push_back(v);
    }

    void remove_duplicate()
    {
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }

    void fast_pop()
    {
        vec.pop_back();
    }

    void clear()
    {
        vec.clear();
    }

    void setRotate(unsigned long r)
    {
        this->rotate = r;
    }

    T &at(size_t idx)
    {
        if (this->vec.size() == 0)
        {
            throw "Index out of range";
        }
        idx += rotate % vec.size();

        while (idx < 0)
            idx = vec.size() + idx;
        idx = idx % vec.size();

        return this->vec[idx];
    }

    T pop()
    {
        T ld = vec.back();
        vec.pop_back();
        return ld;
    }

    T pop_back()
    {
        T ld = vec.back();
        vec.pop_back();
        return ld;
    }

    T back()
    {
        return vec.back();
    }

    T front()
    {
        return vec.front();
    }

    T &operator[](size_t idx)
    {
        return this->at(idx);
    }

    size_t size()
    {
        return vec.size();
    }

    size_t lastIndex()
    {
        return this->size() - 1;
    }

    bool empty()
    {
        return vec.empty();
    }

    auto begin()
    {
        return vec.begin();
    }

    auto end()
    {
        return vec.end();
    }

    auto capacity()
    {
        return vec.capacity();
    }

    void reserve(size_t size)
    {
        vec.reserve(size);
    }

    void resize(size_t size)
    {
        vec.resize(size);
    }
};