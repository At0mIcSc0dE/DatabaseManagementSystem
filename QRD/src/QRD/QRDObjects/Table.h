#pragma once

#include "Base.h"
#include "QRDObject.h"
#include "Record.h"
#include "Column.h"
#include "Field.h"
#include "QRD/Debug/Logger.h"


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
		Column&& AddColumn(const std::string& columnName);

		/**
		* Inserts a new Column to the table
		*
		* @param columnName is the name of the column under which it'll be saved
		* @param index is the position where the new column should be inserted at. Indices start from 0
		*/
		Column&& InsertColumn(const std::string& columnName, const unsigned short index);

		/**
		* Adds a new field as the last field of the table
		*
		* @param fieldName is the name of the field
		*/
		template<const QRDTypes& FIELD_DATA_TYPE>
		Field&& AddField(const std::string& fieldName);

		/**
		* Adds a new field in position index
		*
		* @param fieldName is the name of the field
		* @param index is the position where the field should be inserted
		* @returns a new Field object
		*/
		template<const QRDTypes& FIELD_DATA_TYPE>
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

		/**
		* Properly deletes the table, leaves you with empty table, column and record objects
		*/
		void DeleteTable();

	private:
		/**
		* Datastructure for all columns in this table
		*/
		std::vector<Column> m_Columns;

		/**
		* Datastructure for all fields in this table
		*/
		std::vector<Field> m_Fields;
	};


	Column&& Table::AddColumn(const std::string& columnName)
	{
		Column col = Column(columnName);
		return std::move(col);
	}

	Column&& Table::InsertColumn(const std::string& columnName, const unsigned short index)
	{
		Column col = Column(columnName);
		return std::move(col);
	}

	template<const QRDTypes& FIELD_DATA_TYPE>
	inline Field&& Table::AddField(const std::string& fieldName)
	{
		return Field && ();
	}

	template<const QRDTypes& FIELD_DATA_TYPE>
	inline Field&& Table::InsertField(const std::string& fieldName, const unsigned short index)
	{
		return Field && ();
	}

	template<typename... Args>
	Record&& Table::AddRecord(const Args&... args)
	{
		Record rec = Record();
		return std::move(rec);
	}

	template<typename T>
	inline void func(const T& arg)
	{
		if ((unsigned int)arg == QRD_NULL)
		{
			return;
		}
	}

	template<typename... Args>
	std::tuple<Record>&& Table::GetRecord(const Args&... args)
	{
		std::tuple<Record> records = {};
		(func(args), ...);

		return std::move(records);
	}


}



