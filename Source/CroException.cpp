/*
 * © 2024 CronoGames. All rights reserved.
 * Basic header files i use in most files
 */

#include "CroException.h"
#include <sstream>

CroException::CroException( int line,const char* file ) noexcept
	:
	line( line ),
	file( file )
{}

const char* CroException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* CroException::GetType() const noexcept
{
	return "Cro Exception";
}

int CroException::GetLine() const noexcept
{
	return line;
}

const std::string& CroException::GetFile() const noexcept
{
	return file;
}

std::string CroException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}