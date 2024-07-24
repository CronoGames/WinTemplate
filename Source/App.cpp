/*
 * © 2024 CronoGames. All rights reserved.
 * Basic header files i use in most files
 */

#include "App.h"

App::App( const std::string& commandLine )
:
    wnd( 1280,720,"CroWindow" ),
	commandLine( commandLine )
{
    //
}

App::~App()
{

}

int32 App::Start()
{
    while( bIsRunning )
	{
        if( const auto ecode = CroWindow::ProcessMessages() )
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}

        // execute the game logic
		const float dt = timer.Mark() * speed_factor;
        HandleInput(dt);
        Tick(dt);       
    }
    return{-1};
}

#include <chrono>
#include <thread>
void App::Tick(float dt)
{
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void App::HandleInput(float dt)
{

}