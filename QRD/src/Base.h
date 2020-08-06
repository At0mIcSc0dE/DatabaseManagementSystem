#pragma once

#define QRD_DYNAMIC_LIBRARY 1

#if QRD_DYNAMIC_LIBRARY
	#ifdef DBMS_BUILD
		#define QRD_API __declspec(dllexport)
	#else
		#define QRD_API __declspec(dllimport)
	#endif
#else
	#define QRD_API
#endif

/**
* Disable STL warning: class needs to have dll-interface to be used by client class
*/
#pragma warning(disable : 4251)


/**
* Set to 0 to disable logging or timing
*/
#define QRD_LOG_ACTIVE 1
#define QRD_TIMER_ACTIVE 1


#define QRD_ASSERT(x) if(!(x)) __debugbreak();


namespace QRD
{
	/**
	* SQL DbTypes
	*/
	typedef const char* TEXT;
	typedef const int INTEGER;

	enum DbTypes
	{
		NULL_TYPE = 0, TEXT_TYPE, INTEGER_TYPE
	};

}

