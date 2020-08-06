#pragma once

#include "Base.h"
#include "pch.h"

namespace QRD
{
	class QRD_API Field
	{
	public:
		/**
		* Constructor for Field object
		*
		* @param fieldName is the name under which the field will be stored
		* @param type is the type the field will store
		*/
		Field(const std::string& fieldName, const char type);
	};
}



