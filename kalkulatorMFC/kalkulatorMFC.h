
// kalkulatorMFC.h: główny plik nagłówkowy aplikacji PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "dołącz nagłówek „pch.h” przed dołączeniem tego pliku na potrzeby optymalizacji PCH"
#endif

#include "resource.h"		// główne symbole


// CkalkulatorMFCApp:
// Aby uzyskać implementację klasy, zobacz kalkulatorMFC.cpp
//

class CkalkulatorMFCApp : public CWinApp
{
public:
	CkalkulatorMFCApp();

// Przesłania
public:
	virtual BOOL InitInstance();

// Implementacja

	DECLARE_MESSAGE_MAP()
};

extern CkalkulatorMFCApp theApp;
