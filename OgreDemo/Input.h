#ifndef _INPUT_H_
#define _INPUT_H_
#include "ExampleApplication.h"
class Input : public ExampleFrameListener
{
public:
    Input(RenderWindow* win, Camera* cam) : ExampleFrameListener(win, cam) {}
    ~Input();
    // Input interface
    bool frameStarted(const FrameEvent& evt);
    // TODO: add member function declarations...
protected:
};
#endif //_INPUT_H_