/*
*
* function: ��־ dll API
*
* Date:2016-04-28
*
*    Author: Bill Wang
*/

#include "loggerAPI.h"
#include "logger.h"
#include <iostream>

using namespace std;

void api_InitLogger(const std::string& info_log_filename,
	const std::string& warn_log_filename,
	const std::string& error_log_filename,
	bool isAppend) {

	initLogger(info_log_filename, warn_log_filename, error_log_filename, isAppend);//��ʼ����־�ļ�
}

std::ostream& api_WriteLogger(log_rank_t rank, const std::string reason) {

	return LOG2(rank, reason);
}

//echo����
void echoTest() {
	cout << "Echo Success!!" << endl;
}
