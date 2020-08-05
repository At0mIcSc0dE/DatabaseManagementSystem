#pragma once

#include "QRD/QRD.h"


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
	Application(const std::string& filePath);

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
	* The main database object from the dll
	*/
	QRD::QRDDB m_Database;

	std::unordered_map<std::string, std::vector<std::string>> m_Tables;
};

