#pragma once


#ifdef DBMS_BUILD
	#define DBMS_API __declspec(dllexport)
#else
	#define DBMS_API __declspec(dllimport)
#endif
