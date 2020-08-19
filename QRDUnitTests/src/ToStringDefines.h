#pragma once

#include "CppUnitTest.h"
#include <QRD/QRD.h>
#include <vector>

#define DEF_TO_STRING(type) template<> static std::wstring ToString<type>(const type& t) { return L#type; }\
                            template<> static std::wstring ToString<type>(const type* t) { return L#type; }\
                            template<> static std::wstring ToString<type>(type* t) { return L#type; }


namespace Microsoft 
{
    namespace VisualStudio 
    {
        namespace CppUnitTestFramework
        {
            DEF_TO_STRING(QRD::Database)
            DEF_TO_STRING(QRD::Table);
            DEF_TO_STRING(QRD::Field);
            DEF_TO_STRING(QRD::Record);
            DEF_TO_STRING(std::vector<QRD::Table>);

            //template<> static std::wstring ToString<QRD::Database>(const class QRD::Database& t) { return L"QRD::Database"; }

            //template <typename Q> static std::wstring ToString(const Q& q) { return L"Q"; }
            //template <typename Q> static std::wstring ToString(const Q* q) { return L"Q"; }
            //template <typename Q> static std::wstring ToString(Q* q) { return L"Q"; }
        }
    }
}
