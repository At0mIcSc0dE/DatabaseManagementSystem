#pragma once

#include "Core.h"
#include "QRDObject.h"


namespace QRD
{
	/**
	* Class for table object in databases
	*/
	class QRD_API Table : public QRDObject
	{
	public:
		/**
		* Constructor for Table
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
		void AddColumn(const std::string& columnName);

		/**
		* Inserts a new Column to the table
		*
		* @param columnName is the name of the column under which it'll be saved
		* @param index is the position where the new column should be inserted at. Indices start from 0
		*/
		template<typename COL_DATA_TYPE>
		void InsertColumn(const std::string& columnName, const unsigned short index);

		/**
		* Adds a new record to the table
		* 
		* @param args are the values to insert into the record
		*/
		template<typename... Args>
		void AddRecord(Args... args);
	};
}



