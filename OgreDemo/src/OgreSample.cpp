#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"ogremain_d.lib") 
#else 
#pragma comment(lib,"ogremain.lib") 
#endif 
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT ) 
{ 
        using namespace Ogre; 
        try 
        { 
                /// Root�Ĺ��캯����ᴴ������Factory�Լ�Manager 
                /// �����3�����������ǿ���Ϊ�յģ�����ʡ�ԣ�. 
                /// ��1������ָ���˲�����õ��ļ���. ����ļ���ָ�������ǽ�Ҫʹ�õ�ͼ��������DX or GL)��DLL. 
                /// ��Ȼ��ͼ�γ������Կ϶�Ҫ��ͼ�������ˣ�����������Ϊ�գ���ô���Ǳ����ֶ�ȥ����ͼ������. 
                /// ��2������ָ����OGRE��ͼ�����������ļ��� 
                /// �������ʵ�������ڵ��Ե�ʱ��ʹ�õģ������汾��ʱ��϶��ǲ�Ҫ����. 
                /// ����Root���ShowDialg��ʹ�ã�������̬�����õ�ǰҪʹ�õ�ͼ������. 
                /// ������ǿ���ȷ������Ҫʹ�õ�ͼ����������ȫ�������������Լ���ͼ������. ���������Բο�����. 
                /// ��3������ָ��������Ҫʹ�õ�LOG�ļ��� 
                Root * root = new Root("", 
                                       "", 
                                       ""); 
                /// �����ֶ�����ͼ������ 
#ifdef _DEBUG 
                root->loadPlugin("../ogre_vs11/dll/RenderSystem_Direct3D9_d"); 
#else 
                root->loadPlugin("../ogre_vs11/dll/RenderSystem_Direct3D9"); 
#endif 
                /// ����OGRE����Դ���ض���ResourceGroupManager������,��ͨ��WINDOWSֱ�ӹ���. 
                /// ���ԣ�Ҫ����ʹ��OGRE����Դ���أ����ǻ��ð����ǵ���ԴĿ¼���ӵ����Manager��ȥ. 
                /// ˵���ˣ�������Դ�Ļ���·��. 
                /// �����룬��ǰĿ¼��Ҫ�ӵİ� ^_^ 
                /// ����Ҳ��3�������� 
                /// ��1������ָ��������Ҫ�������Դ�����Ŀ¼�� 
                /// ��2������ָ��������Ҫ�������Դ����ʲô��Դ���� 
                /// ��������ȽϹ��죬�����������Ҫ����ʲôԭ������д�ء� 
                /// ��ʵ�������������OGRE�Ĵ������Ѿ��������. 
                /// ������ļ�ϵͳ���أ��Ͳ鿴FileSystemArchiveFactory�����Ķ������createInstance������ΪFileSystem 
                /// �����ZIPѹ�����أ��Ͳ鿴ZipArchiveFactory�����Ķ������createInstance������ΪZip 
                /// Ҳ����˵��������ֱ�����ArchiveFactory���������ﶨ���Ϊ׼������϶�������. 
                /// ��3�������ͱȽϼ��ˣ����������д����ֻ�Ƕ���Դ��һ���߼��ϵķ���. 
                ResourceGroupManager::getSingleton().addResourceLocation( 
                    ".", "FileSystem", "General"); 
                ResourceGroupManager::getSingleton().addResourceLocation( 
                    "media1", "FileSystem", "General"); 
                /// ���������ⲽ��������Ҫ����Щ��Դ·������ļ���Ϣ����ȡ�������Ա���ٲ���. 
                /// ��������������Ǹ��������µ�. 
                ResourceGroupManager::getSingleton().initialiseAllResourceGroups(); 
                /// �ող���˵�������ǰ�Root��ĵڶ��������������ˣ�Ҳ����˵���ǵ��Լ�ָ��һ��RenderSystem�� 
                /// �Լ������������� 
                /// �������Ǿ�����Plugins����ؽ�OGRE��ĵ�һ��RenderSystem,��������DX 
               //RenderSystem *render_system = *root->getAvailableRenderers().begin(); 
			   RenderSystem * render_system = root->getRenderSystemByName("Direct3D9 Rendering Subsystem");
				/// ����Ϊ����ģʽ 
                render_system->setConfigOption("Full Screen","Yes"); 
                /// �����RenderSystem����ΪϵͳĬ�ϵ� 
                root->setRenderSystem(render_system); 
                /// ���ˣ� ����RenderSystem�����ǾͿ��Գ�ʼ�����ǵ�Root��.(��ʵ���Ǵ������ڵĹ���) 
                /// �������ǰ�RenderSystem������Ҳ��ʾ�ڴ��ڵı�������. 
                RenderWindow *render_win = root->initialise(true,String("my simple orge window,rendersystem : ") + render_system->getName()); 
                /// ��������Ⱦ,SceneManager���봴��һ��������������ǵ���Ϸ��̨�� 
                SceneManager * scene_mgr = root->createSceneManager(ST_GENERIC, "my scene"); 
                /// ���õƹ������ 
                scene_mgr->setAmbientLight(ColourValue(1,1,1)); 
                /// �������ú��ˣ������뻹���и��۲��ߣ�����۲������������Camera 
                Camera * camera = scene_mgr->createCamera("my camera"); 
                camera->setPosition(Vector3(0,0,500)); 
                camera->lookAt(Vector3(0,0,-300)); 
                camera->setNearClipDistance(5); 
                /// ���˹۲��ߣ���������ô���������������أ� 
                /// ���ǻ�����Ҫһ���۾������������Viewport 
                Viewport* vp = render_win->addViewport(camera); 
                vp->setBackgroundColour(ColourValue(0,0,0)); 
                /// ��������camera��ͼ�α���,�������ã�����ͼ������ 
                camera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight())); 
                /// ����ͨ�����������Դģ��ogrehead��������ʾ 
                Entity *ent = scene_mgr->createEntity("Robot","ogrehead.mesh"); 
                SceneNode *node = scene_mgr->getRootSceneNode()->createChildSceneNode("RobotNode"); 
                node->setPosition(50,30,0); 
                node->attachObject(ent); 
                root->startRendering(); 
                delete root; 
        } 
        catch (Ogre::Exception & e) 
        { 
                ::MessageBox( NULL, 
                                e.getFullDescription().c_str(), 
                                "An exception has occured!", 
                                MB_OK | MB_ICONERROR | MB_TASKMODAL); 
        } 
} 