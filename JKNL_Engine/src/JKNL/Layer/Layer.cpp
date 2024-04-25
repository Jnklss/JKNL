#include "jknlpch.h"
#include "Layer.h"

namespace JKNL {

	Layer::~Layer()
	{
	}

	Layer::Layer(const std::string& debugName) 
#ifdef JKNL_DEBUG
		:m_DebugName(debugName)
#endif // JKNL_DEBUG
	{
	}

}


