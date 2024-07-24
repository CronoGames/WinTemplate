#ifndef CROEXCEPTION_H
#define CROEXCEPTION_H
/*
 * © 2024 CronoGames. All rights reserved.
 * Basic header files i use in most files
 */

#include <exception>
#include <string>

class CroException : public std::exception
{
public:
	CroException( int line,const char* file ) noexcept;
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginString() const noexcept;
private:
	int line;
	std::string file;
protected:
	mutable std::string whatBuffer;
};

#endif