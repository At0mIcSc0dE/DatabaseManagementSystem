#pragma once

#include <exception>


namespace QRDTest
{
	class Assert
	{
	public:
		static inline void FailOnCondition(bool condition, const char* message)
		{
			if (condition) throw std::exception(message);
		}

		template<typename T>
		static inline void AreEqual(const T& obj1, const T& obj2, const char* message)
		{
			FailOnCondition(obj1 != obj2, message);
		}

		template<typename T>
		static inline void AreNotEqual(const T& obj1, const T& obj2, const char* message)
		{
			FailOnCondition(obj1 == obj2, message);
		}

		template<typename T, typename Q>
		static inline void AreSameType(const T& obj1, const Q& obj2, const char* message)
		{
			FailOnCondition(typeid(obj1).name() != typeid(obj2).name());
		}

		template<typename T, typename Q>
		static inline void AreNotSameType(const T& obj1, const Q& obj2, const char* message)
		{
			FailOnCondition(typeid(obj1).name() == typeid(obj2).name());
		}

		template<typename T>
		static inline void AreReferenced(T& obj1, T& obj2, const char* message)
		{
			FailOnCondition(&obj1 != &obj2);
		}
	};
}