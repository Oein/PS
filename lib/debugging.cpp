#include <iostream>
#include <ostream>
using namespace std;

#define endl '\n'
#define NOTYPE ""
namespace Debug
{
    const int INDENTSIZE = 2;
    const int TYPEWIDTH = 4;
    int indent = 0;

    void printIndent()
    {
        for (int i = 0; i < indent * INDENTSIZE; i++)
        {
            cout << " ";
        }
    }

    void setIndent(int i)
    {
        indent = i;
    }

    void increaseIndent()
    {
        indent++;
    }

    void decreaseIndent()
    {
        indent--;
    }

    void printType(string type)
    {
        Debug::printIndent();

        if (Debug::indent)
            cout << "└ ";

        if (type.size() == 0)
            return;
        cout << type;
        cout << " # ";
    }
}

#if defined(DONLINE_JUDGE) || defined(ONLINE_JUDGE) || defined(DBOJ)
#define dout(type) \
    if (false)     \
    cout
#else
#define dout(type)          \
    Debug::printType(type); \
    cout
#endif