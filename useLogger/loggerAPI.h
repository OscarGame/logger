/*
*
* function: ��־ dll API
*
* Date:2016-04-28
*
*    Author: Bill Wang
*/

#ifndef _LOGGER_API_H_
#define _LOGGER_API_H_

#include "logger.h"

#define WH_DLL_EXPORTS
#ifdef WH_DLL_EXPORTS
#define WH_DLL_API __declspec(dllexport) //����
#else
#define WH_DLL_API __declspec(dllimport) //����
#endif

extern "C"
{

	WH_DLL_API void api_InitLogger(const std::string& info_log_filename,
		const std::string& warn_log_filename,
		const std::string& error_log_filename,
		bool isAppend = true);

	WH_DLL_API std::ostream& api_WriteLogger(log_rank_t rank, const std::string reason);

	WH_DLL_API void echoTest(); //echo����
}

#endif