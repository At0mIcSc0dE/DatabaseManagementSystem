#pragma once

#include "Core.h"
#include "QRDObjects/Table.h"
#include "QRDObjects/Record.h"

#include "QRDFlags.h"

namespace QRD
{
	class QRD_API QRDDB
	{
	public:
		/**
		* Constructor for QRDDB object
		*/
		QRDDB();

		/**
		*
		*/
		Table&& AddTable(const std::string& tableName, const QRDFlags& flags);

	};
}



