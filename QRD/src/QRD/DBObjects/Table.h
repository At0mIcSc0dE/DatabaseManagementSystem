#pragma once

#include "Base.h"
#include "pch.h"
#include "Field.h"
#include "Record.h"


namespace QRD
{

	struct DbData;

	class QRD_API Table
	{
	public:
		/**
		* Constructor for Table object
		*
		* @param tableName is the name under which the table will be stored
		*/
		Table(const std::string& tableName, std::vector<DbData*>& data);

		template<DbTypes FIELD_DATA_TYPE>
		Field& AddField(const std::string& fieldName);
		
		void DeleteField(const Field& field);
		void DeleteField(const std::string& fieldName);

		template<typename... Args>
		Record& AddRecord(const Args&... data);

		std::tuple<Record> GetRecordsByValues(const std::string& commandStr);
		Record& GetRecordById(const int id);

		void DeleteRecord(const Record& record);
		void DeleteRecord(const std::string& commandStr);


		/**
		* Getter for table name
		*
		* @returns the table's name
		*/
		const std::string& GetTableName() const { return m_TableName; }

	private:
		template<typename T>
		void AddRecordData(const Record& rec, const T& data);

	private:
		const std::string m_TableName;

		std::vector<DbData*>& m_Data;

		/**
		* Represents the index where this table lives in m_Data --> m_Data[m_IndexInData].table, assigned in Database::ReadDb()
		*/
		const int m_IndexInData;
	};


	template<DbTypes FIELD_DATA_TYPE>
	inline Field& Table::AddField(const std::string& fieldName)
	{
		Field field(fieldName, FIELD_DATA_TYPE);
		return field;
	}

	template<typename ...Args>
	inline Record& Table::AddRecord(const Args& ...data)
	{
		Record rec;
		(AddRecordData(rec, data), ...);
		m_Data[m_IndexInData]->records.emplace_back(std::move(rec));
		return m_Data[m_IndexInData]->records[m_Data[m_IndexInData]->records.size() - 1];
	}

	template<typename T>
	inline void Table::AddRecordData(const Record& rec, const T& data)
	{
		rec.AddData(data);
	}

}
