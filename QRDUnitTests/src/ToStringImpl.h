#pragma once

#include <QRD/QRD.h>
#include <vector>

#define DEF_TO_STRING(type) template<> static std::wstring ToString<type>(const class type& t) { return L#type; }


namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            //template<> static std::wstring ToString<QRD::Database>(const class QRD::Database& t) { return L"Database"; }
            //template<> static std::wstring ToString<QRD::Table>(const class QRD::Table& t) { return L"Table"; }
            //template<> static std::wstring ToString<QRD::Field>(const class QRD::Field& t) { return L"Field"; }
            //template<> static std::wstring ToString<QRD::Record>(const class QRD::Record& t) { return L"Record"; }
            DEF_TO_STRING(QRD::Database);
            DEF_TO_STRING(QRD::Table);
            DEF_TO_STRING(QRD::Field);
            DEF_TO_STRING(QRD::Record);
            DEF_TO_STRING(std::vector<QRD::Table>)
        }
    }
}
