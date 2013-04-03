#include "Dome.h"
#include "Input.h"
void Dome::createScene(void)
{
	
    ColourValue c = ColourValue(0.5, 0.5, 0.5);
	mSceneMgr->setAmbientLight(c);
    Entity *e = mSceneMgr->createEntity("ogrehead", "ogrehead.mesh");
    SceneNode *node = static_cast<SceneNode *>(mSceneMgr->getRootSceneNode()->createChild());
    node->attachObject(e);
    node->setPosition(0,0,0);
}

// Create new frame listener
void Dome::createFrameListener(void)
{
    mFrameListener = new Input(mWindow, mCamera);
    mRoot->addFrameListener(mFrameListener);
}