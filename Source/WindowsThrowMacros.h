#ifndef WINDOWSTHROWMACROS_H
#define WINDOWSTHROWMACROS_H
/*
 * © 2024 CronoGames. All rights reserved.
 */

#define CHWND_EXCEPT( hr ) CroWindow::HrException( __LINE__,__FILE__,(hr) )
#define CHWND_LAST_EXCEPT() CroWindow::HrException( __LINE__,__FILE__,GetLastError() )
#define CHWND_NOGFX_EXCEPT() CroWindow::NoGfxException( __LINE__,__FILE__ )

#endif