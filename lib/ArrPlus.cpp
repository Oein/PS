template <typename T>
class ArrPlus
{
public:
    T *vec;
    unsigned long rotate = 0;

private:
    signed long __length = 0;
    signed long __capicity = 0;

public:
    ArrPlus(signed long size)
    {
        vec = new T[size];
        this->__capicity = size;
    }
    ArrPlus(signed long size, T v)
    {
        vec = new T[size];
        for (signed long i = 0; i < size; i++)
        {
            vec[i] = v;
        }
        this->__capicity = size;
        this->__length = size;
    }
    ArrPlus(T *v)
    {
        this->vec = v;
        this->__capicity = sizeof(v) / sizeof(T);
        this->__length = this->__capicity;
    }
    ArrPlus(vector<T> v)
    {
        vec = new T[v.size()];
        for (signed long i = 0; i < v.size(); i++)
        {
            vec[i] = v[i];
        }

        this->__capicity = v.size();
        this->__length = v.size();
    }

    void push(T v)
    {
        if (this->__length == this->__capicity)
            throw "Out of capicity";
        vec[this->__length++] = v;
    }

    void push_back(T v)
    {
        if (this->__length == this->__capicity)
            throw "Out of capicity";
        vec[this->__length++] = v;
    }

    void fast_pop()
    {
        this->__length--;
    }

    void clear()
    {
        this->__length = 0;
    }

    void setRotate(unsigned long r)
    {
        this->rotate = r;
    }

    T &at(signed long idx)
    {
        if (idx >= this->capacity())
            throw "Index out of range (Over)";
        while (idx < 0)
            idx = this->__length + idx;

        idx += rotate % this->__length;
        this->__length = max(this->__length, idx + 1);

        return this->vec[idx];
    }

    T pop()
    {
        T ld = vec[this->__length - 1];
        this->__length--;
        return ld;
    }

    T pop_back()
    {
        T ld = vec[this->__length - 1];
        this->__length--;
        return ld;
    }

    T back()
    {
        return vec[this->__length - 1];
    }

    T front()
    {
        return vec[0];
    }

    T &operator[](signed long idx)
    {
        return this->at(idx);
    }

    signed long size()
    {
        return this->__length;
    }

    signed long lastIndex()
    {
        return this->__length - 1;
    }

    bool empty()
    {
        return this->__length == 0;
    }

    auto begin()
    {
        return vec;
    }

    auto end()
    {
        return vec + this->__length;
    }

    auto capacity()
    {
        return this->__capicity;
    }

    void reserve(signed long size)
    {
        reverse(begin(), end());
    }

    T sum(T init = 0)
    {
        T s = init;
        for (signed long i = 0; i < this->__length; i++)
        {
            s += vec[i];
        }
        return s;
    }

    T avg(T init = 0)
    {
        return this->sum(init) / size();
    }

    string join(string sep = " ")
    {
        ostringstream os(NULL);
        for (signed long i = 0; i < this->__length; i++)
        {
            os << vec[i];
            if (i != this->__length - 1)
                os << sep;
        }
        return os.str();
    }

    void joinprintf(string sep = " ")
    {
        for (signed long i = 0; i < this->__length; i++)
        {
            cout << vec[i];
            if (i != this->__length - 1)
                cout << sep;
        }
    }

    void reverse()
    {
        reverse(this->begin(), this->end());
    }

    string to_string(string sep = ", ")
    {
        ostringstream os(NULL);
        os << "ArrPlus(" << this->__length << ") {";
        for (signed long i = 0; i < this->__length; i++)
        {
            os << vec[i];
            if (i != this->__length - 1)
                os << sep;
        }
        os << "}";
        return os.str();
    }
};