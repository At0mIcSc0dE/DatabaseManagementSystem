#pragma once

#include "Base.h"
#include "pch.h"


namespace QRD
{
	class QRD_API Record
	{
	public:

		template<typename T>

		void AddData(const T& data);

	private:
		std::vector<std::string> m_Data;
	};


	template<typename T>
	inline void Record::AddData(const T& data)
	{
		if (!std::is_convertible<T, std::string>)
			__debugbreak();

		m_Data.emplace_back(data);
	}
}



