/*
 * © 2024 CronoGames. All rights reserved.
 */

// All includes vare here
#include "CroWin.h"
#include "CroHeader.h"
#include "App.h"
#include <iostream>

// Main entry point for windows programs
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	try
	{
		return App{ lpCmdLine }.Start();
	}
	catch( const CroException& e )
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch( ... )
	{
		std::cerr << "Unknown Exception" << '\n';
	}
	return{-1};   
}