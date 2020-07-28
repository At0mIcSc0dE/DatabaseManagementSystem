#pragma once

#include "Core.h"
#include "pch.h"


namespace QRD
{
	class Table;
	class Record;

	class QRD_API QRDObject
	{
	public:
		static void SetFilePath(const std::string& filePath) { m_DBFilePath = filePath; }
		static const std::string& GetFilePath() { return m_DBFilePath; }

	protected:
		/**
		* File path to the .dbs file
		*/
		static std::string m_DBFilePath;
	};

}

