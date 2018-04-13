#include <string>
#include <cassert>

class President
{
public:
    static President& getInstance()
    {
        static President instance;
        return instance;
    }

    President(const President&) = delete;
    President& operator=(const President&) = delete;

private:
    President() {}
};

int main()
{
    const President& p1 = President::getInstance();
    const President& p2 = President::getInstance();

    assert(&p1 == &p2);

    return 0;
}