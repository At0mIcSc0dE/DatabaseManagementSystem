#pragma once

#include "Base.h"
#include "pch.h"
#include "QRDObject.h"


namespace QRD
{
	class QRD_API Field : public QRDObject
	{
	public:
		/**
		* Constructor for Field object
		*
		* @param fieldName is the name of the field
		* @param fieldDataType is the QRD_TYPE of the field
		*/
		Field(const std::string& fieldName, QRDTypes fieldDataType);

		/**
		* Changes the name of the field
		*
		* @param newFieldName is the new name of the field
		*/
		void EditField(const std::string& newFieldName);

		/**
		* Deletes the field and all its data from the entire database
		*/
		void DeleteField();
	
	};

}



