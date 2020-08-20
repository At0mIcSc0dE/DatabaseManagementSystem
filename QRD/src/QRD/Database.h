#pragma once

#include "pch.h"
#include "Base.h"

#include "DBObjects/Table.h"
#include "DBObjects/Record.h"
#include "DBObjects/Field.h"


namespace QRD
{
	/**
	* Main Database class, should be instantiated by the client to manage your database
	*/
	class QRD_API Database
	{
	public:

		/**
		* Constructor for Database object
		*
		* @param filePath is the path to the .dbs file
		* @param tableAmnt is the total amount of tables the program will allocate memory for
		*/
		Database(const std::string& filePath, size_t tableAmnt = 10, size_t fieldAmnt = 10, size_t recordAmnt = 20);

		/**
		* Creates a new table, adds it to m_Data
		*
		* @param tableName is the name the table will have
		* @returns the newly created table
		*/
		Table& CreateTable(const std::string& tableName);

		/**
		* Finds the table by name
		* 
		* @param tableName is the name of the table to search for
		* @returns the found table, empty table object if not found
		*/
		Table& GetTable(const std::string& tableName);

		/**
		* Checks if the table already exists
		* 
		* @param tableName is the name of the table
		* @return true if the table exists else false
		*/
		bool TableExists(const std::string& tableName);

		/**
		* Deletes the table
		*
		* @param table is the table to delete
		*/
		void DeleteTable(const Table& table);

		/**
		* Deletes the table
		*
		* @param tableName is the table's name
		*/
		void DeleteTable(const std::string& tableName);

		/**
		* Updates table id's after deleting a table
		*
		* @param indexOfDeletedElement is the index where the element was before it's deletion
		*/
		void UpdateTableIds(unsigned short indexOfDeletedElement);

		/**
		* Revalidates references which point to the wrong address because of vector resizing
		* 
		* @prarm args are all the invalid references with type Table;
		*/
		template<typename... Args>
		void RevalidateReferences(Args&... args);

		/**
		* Reads database stored in file into memory
		*/
		void ReadDb(size_t fieldAmnt = 10, size_t recordAmnt = 20);

		/**
		* Writes the database stored in memory to file
		*/
		void WriteDb();

		/**
		* Writes everything stored in memory to file and destroys all database objects in memory
		*/
		void ExitDb();

		/**
		* Function should be called before creating any tables to allocate more memory for the vector of tables
		*
		* @param tableAmnt is the amount of tables the client is going to create
		*/
		void ReserveTables(unsigned int tableAmnt);

		/**
		* Compares tables
		*
		* @param other is the other table object
		* @returns true if the tables hold the same data else false
		*/
		bool operator==(const Database& other);

		/**
		* Getter for all tables in .dbs file
		*
		* @returns all tables
		*/
		const std::vector<Table>& GetTables() const { return m_Tables; }

		/**
		* Getter for .dbs file filepath
		* 
		* @returns the path to the .dbs file
		*/
		const std::string& GetFilePath() const { return m_DBFilePath; }

	private:
		void ReadFields(std::ifstream& reader, std::string& line);
		void ReadRecords(std::ifstream& reader, std::string& line);


	private:
		
		/**
		* Datastructure holding all tables and their corresponding records
		*/
		std::vector<Table> m_Tables;

		/**
		* Datastructure used to revalidate references
		* Table* is the memory address of the Table and
		* unsigned int is the index in m_Tables
		*/
		std::vector<std::pair<Table*, unsigned int>> m_TablePosInVec;
		
		/**
		* File path to the .dbs file
		*/
		const std::string m_DBFilePath;
	};


	template<typename ...Args>
	inline void Database::RevalidateReferences(Args& ...args)
	{
		void(*RevalidateReference)(Table& ref, Database* db) = [](Table& ref, Database* db)
		{
			Table* ptr = &ref;
			for (unsigned int i = 0; i < db->m_TablePosInVec.size(); ++i)
			{
				if (db->m_TablePosInVec[i].first == ptr)
				{
					ptr = &db->m_Tables[db->m_TablePosInVec[i].second];
					db->m_TablePosInVec[i].first = ptr;
					break;
				}
			}

			if(&ref != ptr)
				memmove(&ref, ptr, sizeof(Table));
		};
		
		(RevalidateReference(args, this), ...);
	}
}


