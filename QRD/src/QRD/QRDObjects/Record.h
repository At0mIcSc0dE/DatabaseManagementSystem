#pragma once

#include "Base.h"
#include "QRDObject.h"


namespace QRD
{
	class QRD_API Record : public QRDObject
	{
	public:
		/**
		* Sets single data in Record
		*
		* @param args is the data to be stored
		*/
		template<typename... Args>
		void AddData(Args... args);

		/**
		* Edits the record
		*
		* @param args are the arguments to fill the row again
		*/
		//template<typename... Args>
		//void EditRecord(Args... args);

	private:
		/**********************
		**       DEBUG       **
		***********************/
		std::vector<void*> m_RecordData;

	};

	template<typename ...Args>
	inline void Record::AddData(Args ...args)
	{
		(m_RecordData.emplace_back((void*)&args), ...);
	}

}


