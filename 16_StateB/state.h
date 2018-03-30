// state.h
#ifndef STATE_H
#define STATE_H

// 信号灯的状态
class IState
{
public:
    virtual void Handle() = 0;
};

#endif // STATE_H