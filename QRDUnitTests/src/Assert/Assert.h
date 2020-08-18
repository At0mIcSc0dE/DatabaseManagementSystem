#pragma once


namespace QRDTest
{
	class Assert
	{
	public:
		template<typename T>
		static void AreEqual(T& obj1, T& obj2, const char* message);

		static void FailOnCondition(bool condition, const char* message);
	};


	template<typename T>
	inline void Assert::AreEqual(T& obj1, T& obj2, const char* message)
	{
		FailOnCondition(obj1 != obj2);
	}
}


