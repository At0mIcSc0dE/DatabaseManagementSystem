#include "pch.h"
#include "QRDObject.h"

namespace QRD
{
	std::string QRDObject::m_DBFilePath = "";
	std::unordered_map<Table*, std::vector<Record*>> QRDObject::m_Data = {};
}