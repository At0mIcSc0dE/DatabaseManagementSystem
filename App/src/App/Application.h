#pragma once

#include "DatabaseHandler.h"

/**
* Client Application class
*/
class Application
{
public:
	/**
	* Constructor for application
	*
	* @param filePath is the path to the .dbs file
	* @return a new application object
	*/
	Application(const char* filePath);

	/**
	* Function to enter the program's run loop
	*/
	void Run();

private:
	/**
	* The program will continue to run while this variable is true.
	* Set it to false to exit the program.
	*/
	bool m_Running;

	/**
	* Database Handler class for database operations
	*/
	DatabaseHandler dbHandler;
};

