#include "../logger/logger.h"

#pragma comment(lib, "logger.lib")

int main(int argc, char *argv[])
{
	initLogger("whInfolog.txt", "whWarnlog.txt", "whErrolog.txt", false);//��ʼ����־�ļ�
	
	LOG2(_INFO,"first log");
	
	return 0;
}