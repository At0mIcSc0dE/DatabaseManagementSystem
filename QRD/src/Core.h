#pragma once


#ifdef DBMS_BUILD
	#define QRD_API __declspec(dllexport)
#else
	#define QRD_API __declspec(dllimport)
#endif

