#pragma once

#include "Base.h"
#include "Record.h"
#include "Field.h"
#include "QRD/Debug/Logger.h"


namespace QRD
{
	/**
	* Class for the table object in databases
	*/
	class QRD_API Table
	{
	public:
		/**
		* Constructor for Table object
		* 
		* @param tableName is the name under which the table will be saved
		*/
		Table(const std::string& tableName);

		/**
		* Adds a new field as the last field of the table
		*
		* @param fieldName is the name of the field
		*/
		template<DBTypes FIELD_DATA_TYPE>
		Field&& AddField(const std::string& fieldName);

		/**
		* Adds a new field in position index
		*
		* @param fieldName is the name of the field
		* @param index is the position where the field should be inserted
		* @returns a new Field object
		*/
		template<DBTypes FIELD_DATA_TYPE>
		Field&& InsertField(const std::string& fieldName, const unsigned short index);

		/**
		* Adds a new record to the table
		*
		* @param args are the values to insert into the record
		*/
		template<typename... Args>
		Record&& AddRecord(const Args&... args);

		/**
		* Returns the record where the arguments match the ones in the datase
		*
		* @param args are the arguments to identify the record, pass in QRD_NULL for every column that shouldn't be checked
		* @warning currently no way to only check e.g. 2nd and 4th column. We need to be able to know which column should be checked
		*/
		template<typename... Args>
		std::tuple<Record>&& GetRecord(const Args&... args);

	private:
		/**
		* Datastructure for all fields in this table
		*/
		std::vector<Field> m_Fields;

		/**********************
		**       DEBUG       **
		***********************/
		const std::string& m_TableName;
	};


	template<DBTypes FIELD_DATA_TYPE>
	inline Field&& Table::AddField(const std::string& fieldName)
	{
		//Field field(fieldName, (char)FIELD_DATA_TYPE);
		//m_Fields.emplace_back(field);
		//return std::move(field);
		Field* field = new Field(fieldName, (char)FIELD_DATA_TYPE);
		m_Data.emplace_back()
	}

	template<DBTypes FIELD_DATA_TYPE>
	inline Field&& Table::InsertField(const std::string& fieldName, const unsigned short index)
	{
		Field field(fieldName, (char)FIELD_DATA_TYPE);
		m_Fields.emplace_back(field);
		return std::move(field);
	}

	template<typename... Args>
	Record&& Table::AddRecord(const Args&... args)
	{
		Record rec = Record();
		return std::move(rec);
	}

	template<typename... Args>
	std::tuple<Record>&& Table::GetRecord(const Args&... args)
	{
		std::tuple<Record> records = {};
		//(func(args), ...);

		return std::move(records);
	}


}



