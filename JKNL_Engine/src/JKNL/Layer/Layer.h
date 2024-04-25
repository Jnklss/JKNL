#pragma once

#include "JKNL/core.h"
#include "JKNL/Events/Event.h"

namespace JKNL {

	class JKNL_API Layer {

	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

#ifdef JKNL_DEBUG

	inline const std::string& GetName() const { return m_DebugName; }
	
	protected :
		std::string  m_DebugName;

#endif // JKNL_DEBUG
	};
}