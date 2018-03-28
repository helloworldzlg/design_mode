#pragma once

class War;
class State
{
public:
    virtual void Prophase() {}
    virtual void Metaphase() {}
    virtual void Anaphase() {}
    virtual void End() {}
    virtual void CurrentState(War *war) {}
};

class War
{
public:
    War(State *state) : m_state(state), m_days(0)
    {}

    ~War()
    {
        delete m_state;
    }

    void setDays(int days)
    {
        m_days = days;
    }

    int getDays()
    {
        return m_days;
    }

    void setState(State *state)
    {
        delete m_state;
        m_state = state;
    }

    void getState()
    {
        m_state->CurrentState(this);
    }

private:
    State *m_state;
    int m_days;
};