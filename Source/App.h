#ifndef APP_H
#define APP_H
/*
 * © 2024 CronoGames. All rights reserved.
 * Basic header files i use in most files
 */

#include "CroHeader.h"
#include "CroWindow.h"

class App
{
    private:
        CroTimer timer;
	    float speed_factor = 1.0f;
        bool32 bIsRunning{1};
        std::string commandLine;
        CroWindow wnd;
    public:
	    App( const std::string& commandLine = "" );
	    // master frame / message loop
	    int32 Start();
	    ~App();
    private:
        void Tick( float dt );
	    void HandleInput( float dt );
};

#endif