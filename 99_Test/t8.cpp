#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Job
{
public:
    Job(string name) : m_name(name)
    {}

    string getName()
    {
        return m_name;
    }
private:
    string m_name;
};

class JobSeeker
{
public:
    JobSeeker(string name) : m_name(name)
    {}

    void remind(Job& job)
    {
        cout << "hi, " << m_name << " new job: " << job.getName() << " published!!" << endl;
    }
private:
    string m_name;
};

class JobPoster
{
public:
    void AddJob(Job& job)
    {
        Notify(job);
    }

    void Attach(JobSeeker& seeker)
    {
        m_SeekerList.push_back(seeker);
    }

    void Notify(Job& job)
    {
        vector<JobSeeker>::iterator iElement = m_SeekerList.begin();
        for (iElement;
            iElement != m_SeekerList.end();
            ++iElement)
        {
            iElement->remind(job);
        }
    }
private:
    vector<JobSeeker> m_SeekerList;
};

int main()
{
    JobSeeker Jim("Jim");
    JobSeeker Tom("Tom");

    Job engineer("Embedded Engineer");
    JobPoster zhilian;

    zhilian.Attach(Jim);
    zhilian.Attach(Tom);

    zhilian.AddJob(engineer);

    return 0;
}