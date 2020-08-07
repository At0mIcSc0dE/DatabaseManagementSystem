#pragma once

#include "Base.h"
#include "pch.h"
#include "Field.h"
#include "Record.h"


namespace QRD
{

	class QRD_API Table
	{
	public:
		/**
		* Constructor for Table object
		*
		* @param tableName is the name under which the table will be stored
		*/
		Table(const std::string& tableName, const int id);

		template<DbTypes FIELD_DATA_TYPE>
		Field& AddField(const std::string& fieldName);
		
		Field& GetField(const std::string_view fieldName);

		void DeleteField(const Field& field);
		void DeleteField(const std::string& fieldName);

		template<typename... Args>
		Record& AddRecord(const Args&... data);

		template<typename... Args>
		std::vector<Record> GetRecordsByValues(const Args&... commandStrs);

		Record& GetRecordById(const int id);

		const auto& GetRecords() const { return m_Records; }

		void DeleteRecord(const Record& record);
		void DeleteRecord(const std::string& commandStr);

		bool operator==(const Table& other) const;


		/**
		* Getter for table name
		*
		* @returns the table's name
		*/
		const std::string& GetTableName() const { return m_TableName; }

		unsigned short GetTableId() const { return m_Id; }

	private:

	private:
		std::string m_TableName;

		/**
		* List of all records in this table, gets populated in Database::Read()
		*/
		std::vector<Record> m_Records;

		/**
		* List of all fields in this table, gets populated in Database::Read()
		*/
		std::vector<Field> m_Fields;

		/**
		* Represents the index of the table
		*/
		unsigned short m_Id;
	};


	template<DbTypes FIELD_DATA_TYPE>
	inline Field& Table::AddField(const std::string& fieldName)
	{
		Field field(fieldName, FIELD_DATA_TYPE, (unsigned short)m_Fields.size());
		m_Fields.emplace_back(std::move(field));
		return m_Fields[m_Fields.size() - 1];
	}

	template<typename ...Args>
	inline Record& Table::AddRecord(const Args& ...data)
	{
		Record rec;
		(rec.AddData(data), ...);
		m_Records.emplace_back(std::move(rec));
		return m_Records[m_Records.size() - 1];
	}

	template<typename... Args>
	inline std::vector<Record> Table::GetRecordsByValues(const Args&... commandStrs)
	{
		std::vector<Record> recs = m_Records;
		std::vector<std::string_view> commands{ commandStrs... };

		/**
		* Add this and remove recs = m_Records copy if you want to avoid copying all records
		*/

		//for (auto& cmd : commands)
		//{
		//	unsigned short dataIdx = cmd.find(":") + 1;
		//	std::string_view searchData = cmd.substr(dataIdx);
		//	std::string_view fieldName = cmd.substr(0, dataIdx - 1);

		//	Field& field = this->GetField(fieldName);
		//	unsigned short fieldIdx = field.GetFieldId();

		//	for (auto& record : m_Records)
		//	{
		//		for (auto& data : record.GetData())
		//		{
		//			if (data == searchData)
		//			{
		//				if (!std::count(recs.begin(), recs.end(), record))
		//				{
		//					recs.emplace_back(record);
		//				}
		//			}
		//		}
		//	}
		//}

		for (unsigned int i = 0; i < recs.size(); ++i)
		{
			for (auto& cmd : commands)
			{
				unsigned short dataIdx = cmd.find(":") + 1;
				std::string_view searchData = cmd.substr(dataIdx);
				std::string_view fieldName = cmd.substr(0, dataIdx - 1);

				Field& field = this->GetField(fieldName);
				unsigned short fieldId = field.GetFieldId();

				if (recs[i].GetData()[fieldId] != searchData)
				{
					recs.erase(recs.begin() + i);
					--i;
				}
			}
		}

		return recs;
	}

}
