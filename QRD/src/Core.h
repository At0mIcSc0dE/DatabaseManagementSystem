#pragma once


#ifdef DBMS_BUILD
	#define QRD_API __declspec(dllexport)
#else
	#define QRD_API __declspec(dllimport)
#endif

/**
* Set to 0 to disable logging or timing
*/
#define QRD_LOG_ACTIVE 1
#define QRD_TIMER_ACTIVE 1

/**
* Passed into QRD::Table::GetRecord if column should be skipped
* @warning if the user searches for the value defined in QRD_NULL QRD won't actually search for it
*/
#define QRD_NULL 0xFFFFFFFFF



namespace QRD
{
	/**
	* SQL types
	*/
	typedef const char* TEXT;
	typedef const int INTEGER;
}

