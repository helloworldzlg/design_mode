// context.h
#ifndef CONTEXT_H
#define CONTEXT_H

#include "concrete_state.h"

// 交通信号灯
class TrafficLights
{
public:
    TrafficLights() { m_pState = new RedLight(this); }
    void SetState(IState* state) { m_pState = state; }
    void Request() { m_pState->Handle(); }

private:
    IState* m_pState;
};

#endif // CONTEXT_H