// concrete_state.h
#ifndef CONCRETE_STATE_H
#define CONCRETE_STATE_H

#include "state.h"

class TrafficLights;

// 红灯
class RedLight : public IState
{
public:
    RedLight(TrafficLights* context);
    virtual void Handle() override;

private:
    TrafficLights* m_pContext;
};

// 绿灯
class GreenLight : public IState
{
public:
    GreenLight(TrafficLights* context);
    virtual void Handle() override;

private:
    TrafficLights* m_pContext;
};

// 黄灯
class YellowLight : public IState
{
public:
    YellowLight(TrafficLights* context);
    virtual void Handle() override;

private:
    TrafficLights* m_pContext;
};

#endif // CONCRETE_STATE_H