#include "LogFile.h"

//#include <fstream>
//#include <stdlib.h>
//#include <iostream>
#include <stdio.h>

using namespace std;

cLogFile::cLogFile(string sFilename, bool bAppend)
{
	logFileName="AI/RAI/"+sFilename;
	if( !bAppend )
	{
		FILE * pFile;
		pFile = fopen(logFileName.c_str(),"wt");
		fclose(pFile);
//		ofstream oLog( logFileName.c_str() );
//		oLog.close();
	}

	logFile = fopen(logFileName.c_str(),"at");
//	logFile = new ofstream();
//	logFile->open( logFileName.c_str(), ios::app );
}

cLogFile::~cLogFile()
{
	fclose(logFile);
//	logFile->close();
//	delete logFile;
}

cLogFile& cLogFile::operator<<(float message)
{
	if( message - int(message) > 0.0 )
		fprintf(logFile, "%1.2f", message);
	else
		fprintf(logFile, "%1.0f", message);
	return *this;
}
/*
cLogFile& cLogFile::operator<<(const char* message)
{
	fprintf(logFile, "%s", message);
	return *this;
}
*/
cLogFile& cLogFile::operator<<(string message)
{
	fprintf(logFile, "%s", message.c_str());
	return *this;
}

void cLogFile::Write(string message)
{
	fprintf(logFile, "%s", message.c_str());
//  fputs(message.c_str(),logFile);
//  *logFile<<message.c_str();
//	logFile->flush();
}

void cLogFile::Write(float message)
{
	if( message - int(message) > 0.0 )
		fprintf(logFile, "%1.2f", message);
	else
		fprintf(logFile, "%1.0f", message);
//	*logFile<<message;
//	logFile->flush();
}
/*
void cLogFile::Write(int message)
{
	*logFile<<message;
	logFile->flush();
}
*/
