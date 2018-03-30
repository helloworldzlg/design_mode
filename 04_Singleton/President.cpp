#include <string>
#include <cassert>

class President
{
public:
    static President &getInstance()
    {
        static President g_president;
        return g_president;
    }

    President(const President&) = delete;
    President& operator=(const President&) = delete;

private:
    President() {}
};

int main()
{
    const President &president1 = President::getInstance();
    const President &president2 = President::getInstance();

    assert(&president1 == &president2);
}