#pragma once

#include "Base.h"



namespace QRD
{
	class QRD_API Record
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

	};

	template<typename ...Args>
	inline void Record::AddData(Args ...args)
	{

	}

}


