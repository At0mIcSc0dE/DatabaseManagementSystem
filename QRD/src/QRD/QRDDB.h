#pragma once

#include "Base.h"
#include "QRDObjects/Table.h"
#include "QRDObjects/Record.h"

#include "GlobalFlags.h"

namespace QRD
{

	class QRD_API QRDDB
	{
	public:
		/**
		* Constructor for QRDDB object
		*
		* @param dbFilePath is the path to the .dbs file
		*/
		QRDDB(const std::string& dbFilePath);

		/**
		* Adds a new table to the database file
		* 
		* @param tableName is the name of the new table
		* @param flags are flags to change creation of table
		* @returns a new Table object
		*/
		Table& AddTable(const std::string& tableName, const GlobalFlags& flags = FlagTypes::NONE);

		/**
		* Searches for the table with given table name
		*
		* @param tableName is the name of the target table
		* @returns a new Table object
		*/
		Table&& GetTable(const std::string& tableName);

		/**
		* Reads from the .dbs file and populates QRD::QRDObject::m_Data, usually doesn't have to be called by the client
		*/
		void Read();

		/**
		* Function writes all the data stored in memory into the .dbs file
		*/
		void Write();

		/**
		* Function should be called before exiting the program to write the data to the .dbs file
	    * And to properly close all QRDObjects
		*/
		void ExitQRD();
		
		//void Create(std::unordered_map<std::string, std::vector<std::string>> data);


		/**********************
		**       DEBUG       **
		***********************/
		//auto& GetData() { return m_Data; }

	private:
		std::unordered_map<Table*, std::vector<Record*>> m_Data;
		const std::string& m_DBFilePath;
	};
}



