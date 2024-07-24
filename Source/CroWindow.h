#ifndef CROWINDOW_H
#define CROWINDOW_H
/*
 * © 2024 CronoGames. All rights reserved.
 */

#include "CroHeader.h"
#include <Windows.h>
#include <optional>
#include "Keyboard.h"
#include "Mouse.h"

class CroWindow
{
public:
	class Exception : public CroException
	{
		using CroException::CroException;
	public:
		static std::string TranslateErrorCode( HRESULT hr ) noexcept;
	};
	class HrException : public Exception
	{
	public:
		HrException( int line,const char* file,HRESULT hr ) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorDescription() const noexcept;
	private:
		HRESULT hr;
	};
	class NoGfxException : public Exception
	{
	public:
		using Exception::Exception;
		const char* GetType() const noexcept override;
	};
private:
// singleton manages registration/cleanup of window class
	class WindowClass
	{
	public:
		static const char* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass( const WindowClass& ) = delete;
		WindowClass& operator=( const WindowClass& ) = delete;
		static constexpr const char* wndClassName = "CroWindowClass";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};
    private:
    	int width;
	    int height;
	    HWND hWnd;
        bool cursorEnabled = true;
        std::vector<BYTE> rawBuffer;
    public:
        Keyboard kbd;
        Mouse mouse;
    public:
	    CroWindow( int width,int height,const char* name );
	    ~CroWindow();
	    CroWindow( const CroWindow& ) = delete;
	    CroWindow& operator=( const CroWindow& ) = delete;
        static std::optional<int> ProcessMessages() noexcept;
    private:
        void ConfineCursor() noexcept;
	    void FreeCursor() noexcept;
	    void ShowCursor() noexcept;
	    void HideCursor() noexcept;
        static LRESULT CALLBACK HandleMsgSetup( HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam ) noexcept;
	    static LRESULT CALLBACK HandleMsgThunk( HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam ) noexcept;
	    LRESULT HandleMsg( HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam ) noexcept;
};

#endif