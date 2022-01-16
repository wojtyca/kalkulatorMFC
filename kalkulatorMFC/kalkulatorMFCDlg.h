
// kalkulatorMFCDlg.h: plik nagłówkowy
//
#include <string>
#pragma once

// okno dialogowe CkalkulatorMFCDlg
class CkalkulatorMFCDlg : public CDialogEx
{
// Konstrukcja
public:
	CkalkulatorMFCDlg(CWnd* pParent = nullptr);	// konstruktor standardowy

// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KALKULATORMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// obsługa DDX/DDV


// Implementacja
protected:
	HICON m_hIcon;

	// Wygenerowano funkcje mapy komunikatów
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Edit_result;
	std::string hextemp1,hextemp2;
	bool Flag, Bin, Oct, Hex;
	int opera, i, j;
	long long number0, number1, number2;
	float decimal1, decimal2, decimal0;
	CString str1, str2;



	afx_msg void OnBnClickedB1();
	afx_msg void OnBnClickedB2();
	afx_msg void OnBnClickedB5();
	afx_msg void OnBnClickedB0();
	afx_msg void OnBnClickedB3();
	afx_msg void OnBnClickedB4();
	afx_msg void OnBnClickedB6();
	afx_msg void OnBnClickedB7();
	afx_msg void OnBnClickedB8();
	afx_msg void OnBnClickedB9();
	afx_msg void OnBnClickedBPlus();
	afx_msg void OnBnClickedBMinus();
	afx_msg void OnBnClickedBMult();
	afx_msg void OnBnClickedBDiv();
	afx_msg void OnBnClickedBEq();
	afx_msg void OnBnClickedBA();
	afx_msg void OnBnClickedBB();
	afx_msg void OnBnClickedBC();
	afx_msg void OnBnClickedBD();
	afx_msg void OnBnClickedBE();
	afx_msg void OnBnClickedBF();
	afx_msg void OnBnClickedBDelete();
	afx_msg void OnBnClickedCBin();
	afx_msg void OnBnClickedCOct();
	afx_msg void OnBnClickedCHex();
	afx_msg void OnBnClickedBDot();


};
