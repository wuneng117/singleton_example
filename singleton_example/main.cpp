#include <tchar.h>
#include "singleton.cpp"

class TextureMgr : public Singleton <TextureMgr>
{
public:
	const char* GetName(){ return "this is TextureMgr"; }
	// ...
};


#define g_TextureMgr TextureMgr::getInstance()

int _tmain(int argc, _TCHAR* argv[])
{
	//只初始化一遍
	new TextureMgr;

	const char* stone1 = TextureMgr::getInstance()->GetName();
	const char* stone2 = g_TextureMgr->GetName();
	// ...

	return 0;
}