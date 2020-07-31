#pragma once

#include "Base.h"
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
		* @param newColumnName is the new column name of the column
		*/
		void EditColumn(const std::string& newColumnName);
		
		/**
		* Deletes current column
		*/
		void DeleteColumn();

	private:
		/**********************
		**       DEBUG       **
		***********************/
		const std::string& m_ColumnName;

	};
}


