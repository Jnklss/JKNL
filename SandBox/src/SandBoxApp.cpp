#include "JKNL.h"

class SandBox : public JKNL::Application 
{
public:
	SandBox(){ }

	~SandBox()
	{

	}
};

JKNL::Application* JKNL::CreateApplication()
{
	return new SandBox();
}