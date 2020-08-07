#pragma once

#include "Base.h"
#include "pch.h"


namespace QRD
{
	class QRD_API Field
	{
	public:
		Field(const std::string& fieldName, const DbTypes& dbType, const unsigned short fieldId);

		const std::string& GetFieldName() const { return m_FieldName; }
		unsigned short GetFieldId() const { return m_Id; }
	private:
		std::string m_FieldName;
		DbTypes m_FieldType;

		unsigned short m_Id;

		std::vector<std::string> m_Data;
	};

}

