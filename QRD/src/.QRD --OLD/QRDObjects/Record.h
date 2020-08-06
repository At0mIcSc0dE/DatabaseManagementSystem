#pragma once

#include "Base.h"
#include "pch.h"


namespace QRD
{
	class QRD_API Record
	{
	public:
		/**
		* Sets single data in Record
		*
		* @param args is the data to be stored
		*/
		void AddData(const std::string& data, DBTypes RECORD_DATA_TYPE);

	private:
		std::vector<std::pair<DBTypes, std::string>> m_RecordData;
	};

	inline void Record::AddData(const std::string& data, DBTypes RECORD_DATA_TYPE)
	{
		m_RecordData.emplace_back(std::pair<DBTypes, std::string>{ RECORD_DATA_TYPE, data });
	}

}


