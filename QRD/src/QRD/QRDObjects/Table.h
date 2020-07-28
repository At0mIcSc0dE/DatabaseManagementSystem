#pragma once

#include "Core.h"
#include "QRDObject.h"
#include "Record.h"
#include "Column.h"


namespace QRD
{
	/**
	* Class for the table object in databases
	*/
	class QRD_API Table : public QRDObject
	{
	public:
		/**
		* Constructor for Table object
		* 
		* @param tableName is the name under which the table will be saved
		*/
		Table(const std::string& tableName);

		/**
		* Adds a new Column to the table, new column will be the last
		* 
		* @param columnName is the name of the column under which it'll be saved
		*/
		template<typename COL_DATA_TYPE>
		Column&& AddColumn(const std::string& columnName);

		/**
		* Inserts a new Column to the table
		*
		* @param columnName is the name of the column under which it'll be saved
		* @param index is the position where the new column should be inserted at. Indices start from 0
		*/
		template<typename COL_DATA_TYPE>
		Column&& InsertColumn(const std::string& columnName, const unsigned short index);

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
		* @param args are the arguments to identify the record
		* @warning currently no way to only check e.g. 2nd and 4th column. We need to be able to know which column should be checked
		*/
		template<typename... Args>
		std::tuple<Record&>&& GetRecord(const Args&... args);

		/**
		* Properly deletes the table, leaves you with empty table, column and record objects
		*/
		void DeleteTable();

	private:
		/**
		* Datastructure for all columns in this table
		*/
		//std::vector<Column> m_Columns;
	};


	template<typename COL_DATA_TYPE>
	Column&& Table::AddColumn(const std::string& columnName)
	{
		return Column(columnName);
	}

	template<typename COL_DATA_TYPE>
	Column&& Table::InsertColumn(const std::string& columnName, const unsigned short index)
	{
		return Column(columnName);
	}

	template<typename... Args>
	Record&& Table::AddRecord(const Args&... args)
	{
		return Record();
	}

	template<typename... Args>
	std::tuple<Record&>&& Table::GetRecord(const Args&... args)
	{
		std::tuple<Record> records = {};
		
		return std::move(records);
	}

}



