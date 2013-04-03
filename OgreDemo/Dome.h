#ifndef _DOME_H_
#define _DOME_H_
#include "ExampleApplication.h"
class Dome : public ExampleApplication {
public:
    Dome();
    ~Dome();
    void createScene(void);
    void createFrameListener(void);
protected:
    // Dome variables
};
#endif //_DOME_H_