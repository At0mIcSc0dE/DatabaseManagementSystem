#pragma once

#include "Core.h"

#define BIT(x) (1 << x)


namespace QRD
{
	typedef int QRDFlag;

	enum FlagTypes
	{
		NONE = 0,
		IfNotExist = BIT(0)
	};


	class QRD_API QRDFlags
	{
	public:
		/**
		* Constructor for QRDFlags object
		*
		* @param flag is a flag to be added to m_Flags
		*/
		QRDFlags(const FlagTypes flag)
			: m_Flags(0)
		{
			m_Flags | flag;
		}

		/**
		* Constructor for QRDFlags object
		*
		* @param flag is a flag to be added to m_Flags
		*/
		QRDFlags(const QRDFlag flag)
			: m_Flags(0)
		{
			m_Flags | flag;
		}

		/**
		* Checks if flag is conatined in QRDFLags object
		*
		* returns true if flag in QRDFlags object else false
		*/
		bool HasFlag(QRDFlag flag)
		{
			return m_Flags & flag;
		}

	private:
		int m_Flags;
	};
}

