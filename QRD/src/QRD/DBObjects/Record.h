#pragma once

#include "Base.h"
#include "pch.h"


namespace QRD
{
	class QRD_API Record
	{
	public:

		template<typename T/*, class Enable = std::enable_if_t<std::is_convertible_v<T, std::string>>*/>
		void AddData(const T& data);

		const std::vector<std::string>& GetData() const { return m_Data; }

		bool operator==(const Record& other) const;

	private:
		std::vector<std::string> m_Data;
	};


	template<typename T>
	inline void Record::AddData(const T& data)
	{
		std::stringstream ss;
		ss << data;
		m_Data.emplace_back(ss.str());
	}
}



