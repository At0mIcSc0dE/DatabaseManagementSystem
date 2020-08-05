#pragma once

#include "Base.h"

#define BIT(x) (1 << x)

namespace QRD
{
	typedef int GlobalFlag;

	enum FlagTypes
	{
		NONE = 0,
		IfNotExist = BIT(0)
	};


	class QRD_API GlobalFlags
	{
	public:
		/**
		* Constructor for GlobalFlags object
		*
		* @param flag is a flag to be added to m_Flags
		*/
		GlobalFlags(const FlagTypes flag)
			: m_Flags(0)
		{
			m_Flags |= flag;
		}

		/**
		* Constructor for GlobalFlags object
		*
		* @param flag is a flag to be added to m_Flags
		*/
		GlobalFlags(const GlobalFlag flag)
			: m_Flags(0)
		{
			m_Flags |= flag;
		}

		/**
		* Checks if flag is conatined in GlobalFlags object
		*
		* returns true if flag in GlobalFlags object else false
		*/
		bool HasFlag(GlobalFlag flag)
		{
			return m_Flags & flag;
		}

	private:
		GlobalFlag m_Flags;
	};
}

