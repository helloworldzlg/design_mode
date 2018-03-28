#pragma once
#include "BaseObserver.h"

class BlogCSDN : public Blog
{
private:
    string m_name;

public:
    BlogCSDN(string name) : m_name(name)
    {}

    ~BlogCSDN()
    {}

    void SetStatus(string s)
    {
        m_status = "CSND: " + m_name + s;
    }

    string GetStatus()
    {
        return m_status;
    }
};

class ObserverBlog : public Observer
{
private:
    string m_name;
    Blog *m_blog;

public:
    ObserverBlog(string name, Blog *blog) :
    m_name(name), m_blog(blog)
    {}

    ~ObserverBlog()
    {}

    void Update()
    {
        string status = m_blog->GetStatus();
        cout << m_name << "-----" << status << endl;
    }
};