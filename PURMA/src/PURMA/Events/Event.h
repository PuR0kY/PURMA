#pragma once
#include "purpch.h"
#include "PURMA/Core.h"

namespace PURMA {
	/*
	Events in PURMA are currently blocking, meaning when an event occurs, it 
	immediately gets dispatched and must be dealt with right then an there.
	For the future, a better strategy might be to buffer events in an event bus 
	and process them during the "event" part of the update stage.
	*/

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class PUR_API Event
	{
		/* NOTE: "friend" allows another class or function to access private or protected members of this class 
			Here it means that Dispatcher is allowed to modify Event::m_Handled
		 */
		friend class EventDispatcher;
	public:
		/* const means: This function does not modify the state of the object. (const-correctness) */
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		// T& means Any Type Reference
		using EventFn = std::function<bool(T&)>;
	public:
		/* NOTE: we receive Event Reference which means it could be ANY Event Type */
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			// If event type matches Function type
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				// calls that function with that event
				/* NOTE: &m_Event gives you pointer of the base Event object */
				/* NOTE: (T*)&m_Event casts that pointer to the derived Type T* */
				/* NOTE: T is template parameter */
				/* NOTE: is needed because the function expects T& (reference), not T* (pointer) */

				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	// Logs events string
	inline std::ostream& operator <<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}