#pragma once

#include "DBMS/DatabaseManagementSystem.h"

#define BIT(x) (1 << x)


/**
* Enum defines flags useable in any funcions accepting int flags as parameters
*/
enum Flags
{
	/**
	* Add this flag to avoid checking if the table or field already exist
	*/
	ALLOW_DUPLICATE = BIT(0)
};


/**
* TO BE ADDED HERE
*/
class DatabaseHandler
{

public:
	void CreateTable(const char* tableName, int flags = 0);

private:
	/**
	* Function checks if flag is in flags
	*
	* @param flags are all the flags of the object
	* @param flag is the parameter that will be checked if it's in flags
	* @returns true if flag is in flags else false
	*/
	bool HasFlag(int flags, Flags flag);

};

