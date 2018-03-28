#include "SpecificObserver.h"

int main()
{
    Blog* blog = new BlogCSDN("zhanglg");
    Observer *observer1 = new ObserverBlog("tutupig", blog);

    blog->Attach(observer1);
    blog->SetStatus("haha");
    blog->Notify();

    delete blog;
    delete observer1;

    return 0;
}