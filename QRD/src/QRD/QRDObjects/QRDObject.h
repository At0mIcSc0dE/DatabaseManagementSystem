#pragma once

#include "Base.h"
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

		/**
		* Datastructure holding all Records which need to be written to the file
		*/
		static std::unordered_map<Table*, std::vector<Record*>> m_Data;
	};

}

