#pragma once


#ifdef DBMS_BUILD
	#define QRD_API __declspec(dllexport)
#else
	#define QRD_API __declspec(dllimport)
#endif

#define QRD_LOG_ACTIVE 1
#define QRD_TIMER_ACTIVE 1


namespace QRD
{
	typedef const char* TEXT;
	typedef const int INTEGER;
}

