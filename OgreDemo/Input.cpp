#include "Input.h"
bool Input::frameStarted(const FrameEvent& evt)
{
    mKeyboard->capture();
	if(mKeyboard->isKeyDown(OIS::KC_ESCAPE))
        return false;
    return true;
}