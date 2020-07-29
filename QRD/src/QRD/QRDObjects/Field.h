#pragma once

#include "Base.h"
#include "pch.h"
#include "QRDObject.h"


namespace QRD
{
	class QRD_API Field : public QRDObject
	{
	public:
		template<typename FIELD_DATA_TYPE>
		Field(const std::string& fieldName);

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


	template<typename FIELD_DATA_TYPE>
	inline Field::Field(const std::string& fieldName)
	{
	}
}



