#pragma once

#include "Core.h"
#include "QRDObject.h"


namespace QRD
{
	class QRD_API Column : public QRDObject
	{
	public:
		/**
		* Constructor for Column object
		*
		* @param columnName is the name of the column
		*/
		Column(const std::string& columnName);

		/**
		* Changes the column name
		*
		* @param oldColumnName is the column name which should be switched with new one
		* @param newColumnName is the new column name of the column
		*/
		void EditColumn(const std::string& oldColumnName, const std::string& newColumnName);
		
		/**
		* Removes column with given name
		*
		* @param columnName is the name of the column which should be removed
		*/
		void DeleteColumn(const std::string& columnName);

	};
}


