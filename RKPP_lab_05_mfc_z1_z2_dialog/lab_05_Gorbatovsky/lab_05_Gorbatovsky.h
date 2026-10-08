
// lab_05_Gorbatovsky.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Clab05GorbatovskyApp:
// Сведения о реализации этого класса: lab_05_Gorbatovsky.cpp
//

class Clab05GorbatovskyApp : public CWinApp
{
public:
	Clab05GorbatovskyApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Clab05GorbatovskyApp theApp;
