#pragma once

#include "pch.h"
#include "Base.h"


namespace QRD
{
	/**
	* Field class which stores the name and type of the field
	*/
	class QRD_API Field
	{
		friend class Table;
	public:
		/**
		* Constructor for field object
		*
		* @param fieldName is the name of the field
		* @param dbType is the type of data the field will store
		* @param fieldId is the id of the field;
		*/
		Field(const std::string& fieldName, const DbTypes& dbType, const unsigned short fieldId);

		/**
		* Getter for field name
		*
		* @returns the field's name
		*/
		const std::string& GetFieldName() const { return m_FieldName; }

		/**
		* Getter for field id
		*
		* @returns the field's id
		*/
		unsigned short GetFieldId() const { return m_FieldId; }

		/**
		* Getter for field type
		*
		* @returns the field's type
		*/
		const DbTypes GetFieldType() const { return m_FieldType; }
	
		/**
		* Comparison operator, compares all data in field
		* 
		* @param other is the other Field object to compare to
		* @returns true if both field objects hold the same data, else false
		*/
		bool operator==(const Field& other);

		/************************
		**** DEBUG FUNCTIONS ****
		*************************/
		inline std::string ToString() const
		{

			std::string fieldType = "Undefined type";
			switch (m_FieldType)
			{
			case TEXT: fieldType = "Text (" + std::to_string(TEXT) + ')'; break;
			case NUMBER: fieldType = "Number (" + std::to_string(NUMBER) + ')'; break;
			}

			std::stringstream ss;
			ss << "Field object: "
				<< "\n\t[Field::Location]: " << this
				<< "\n\t[Field::m_FieldName]: " << m_FieldName
				<< "\n\t[Field::m_FieldType]: " << fieldType
				<< "\n\t[Field::m_FieldId]: " << m_FieldId << '\n';

			return ss.str();
		}

	private:
		/**
		* Field class which stores the name and type of the field
		*/
		Field() = default;

	private:
		/**
		* The field's name
		*/
		std::string m_FieldName;

		/**
		* The field's type
		*/
		DbTypes m_FieldType;

		/**
		* Represents id in Table::m_Fields
		*/
		unsigned short m_FieldId;
	};

}

