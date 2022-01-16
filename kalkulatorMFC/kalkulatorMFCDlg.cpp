
// kalkulatorMFCDlg.cpp: plik implementacji
//

#include "framework.h"
#include "kalkulatorMFC.h"
#include "kalkulatorMFCDlg.h"
#include "afxdialogex.h"
#include "Convert.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Okno dialogowe CAboutDlg używane na potrzeby informacji o aplikacji

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // obsługa DDX/DDV

// Implementacja
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// okno dialogowe CkalkulatorMFCDlg



CkalkulatorMFCDlg::CkalkulatorMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KALKULATORMFC_DIALOG, pParent)
	, Edit_result(_T(""))

{
	number0 = number1 = number2 = 0;
	decimal0 = decimal1 = decimal2 = 0;
	hextemp1 = hextemp2 = {};
	str1 = str2 = _T("");
	Flag = true;
	Bin = Oct = Hex = false;  
	opera = j = 0;
	i = 1;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkalkulatorMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Edit_result);

}

BEGIN_MESSAGE_MAP(CkalkulatorMFCDlg, CDialogEx)

	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_B1, &CkalkulatorMFCDlg::OnBnClickedB1)
	ON_BN_CLICKED(IDC_B2, &CkalkulatorMFCDlg::OnBnClickedB2)
	ON_BN_CLICKED(IDC_B5, &CkalkulatorMFCDlg::OnBnClickedB5)
	ON_BN_CLICKED(IDC_B0, &CkalkulatorMFCDlg::OnBnClickedB0)
	ON_BN_CLICKED(IDC_B3, &CkalkulatorMFCDlg::OnBnClickedB3)
	ON_BN_CLICKED(IDC_B4, &CkalkulatorMFCDlg::OnBnClickedB4)
	ON_BN_CLICKED(IDC_B6, &CkalkulatorMFCDlg::OnBnClickedB6)
	ON_BN_CLICKED(IDC_B7, &CkalkulatorMFCDlg::OnBnClickedB7)
	ON_BN_CLICKED(IDC_B8, &CkalkulatorMFCDlg::OnBnClickedB8)
	ON_BN_CLICKED(IDC_B9, &CkalkulatorMFCDlg::OnBnClickedB9)
	ON_BN_CLICKED(IDC_B_PLUS, &CkalkulatorMFCDlg::OnBnClickedBPlus)
	ON_BN_CLICKED(IDC_B_MINUS, &CkalkulatorMFCDlg::OnBnClickedBMinus)
	ON_BN_CLICKED(IDC_B_MULT, &CkalkulatorMFCDlg::OnBnClickedBMult)
	ON_BN_CLICKED(IDC_B_DIV, &CkalkulatorMFCDlg::OnBnClickedBDiv)
	ON_BN_CLICKED(IDC_B_EQ, &CkalkulatorMFCDlg::OnBnClickedBEq)
	ON_BN_CLICKED(IDC_B_A, &CkalkulatorMFCDlg::OnBnClickedBA)
	ON_BN_CLICKED(IDC_B_B, &CkalkulatorMFCDlg::OnBnClickedBB)
	ON_BN_CLICKED(IDC_B_C, &CkalkulatorMFCDlg::OnBnClickedBC)
	ON_BN_CLICKED(IDC_B_D, &CkalkulatorMFCDlg::OnBnClickedBD)
	ON_BN_CLICKED(IDC_B_E, &CkalkulatorMFCDlg::OnBnClickedBE)
	ON_BN_CLICKED(IDC_B_F, &CkalkulatorMFCDlg::OnBnClickedBF)
	ON_BN_CLICKED(IDC_B_DELETE, &CkalkulatorMFCDlg::OnBnClickedBDelete)
	ON_BN_CLICKED(IDC_C_BIN, &CkalkulatorMFCDlg::OnBnClickedCBin)
	ON_BN_CLICKED(IDC_C_OCT, &CkalkulatorMFCDlg::OnBnClickedCOct)
	ON_BN_CLICKED(IDC_C_HEX, &CkalkulatorMFCDlg::OnBnClickedCHex)
	ON_BN_CLICKED(IDC_B_DOT, &CkalkulatorMFCDlg::OnBnClickedBDot)
END_MESSAGE_MAP()


// Procedury obsługi komunikatów CkalkulatorMFCDlg

BOOL CkalkulatorMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_B_A)->EnableWindow(0);  //wygaszone ikony hexa na starcie
	GetDlgItem(IDC_B_B)->EnableWindow(0);
	GetDlgItem(IDC_B_C)->EnableWindow(0);
	GetDlgItem(IDC_B_D)->EnableWindow(0);
	GetDlgItem(IDC_B_E)->EnableWindow(0);
	GetDlgItem(IDC_B_F)->EnableWindow(0);
	// Dodaj pozycję „Informacje...” do menu systemowego.

	// Element IDM_ABOUTBOX musi należeć do zakresu poleceń systemowych.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Ustaw ikonę dla tego okna dialogowego. Struktura wykonuje to automatycznie
	//  gdy okno główne aplikacji nie jest oknem dialogowym
	SetIcon(m_hIcon, TRUE);			// Ustaw duże ikony
	SetIcon(m_hIcon, FALSE);		// Ustaw małe ikony

	// TODO: Dodaj tutaj dodatkowe inicjowanie

	return TRUE;  // zwracaj wartość TRUE, dopóki fokus nie zostanie ustawiony na formant
}

void CkalkulatorMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Jeśli dodasz przycisk minimalizacji do okna dialogowego, będziesz potrzebować poniższego kodu
//  aby narysować ikonę. Dla aplikacji MFC używających modelu dokumentu/widoku
//  to jest wykonywane automatycznie przez strukturę.

void CkalkulatorMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // kontekst urządzenia dotyczący malowania

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Wyśrodkuj ikonę w prostokącie klienta
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Rysuj ikonę
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// System wywołuje tę funkcję, aby uzyskać kursor wyświetlany podczas przeciągania przez użytkownika
//  zminimalizowane okno.
HCURSOR CkalkulatorMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
Converting Change;
			

											// ***TYPY WPROWADZANYCH DANYCH*** //


	// **BINARNY**

void CkalkulatorMFCDlg::OnBnClickedCBin()
{
	Bin = !Bin;							//włącz/wyłącz wprowadzanie binarne
							
	if (i == 0) {						
		i = 1;							
	}									// Widoczność przycisków
	else {								
		i = 0;							
	}									
	GetDlgItem(IDC_C_OCT)->EnableWindow(i);
	GetDlgItem(IDC_C_HEX)->EnableWindow(i);
	GetDlgItem(IDC_B_DOT)->EnableWindow(i);
}


	//**Oktalny**

void CkalkulatorMFCDlg::OnBnClickedCOct()
{
	Oct = !Oct;

	if (i == 0) {
		i = 1;
	}
	else {
		i = 0;
	}

	GetDlgItem(IDC_C_BIN)->EnableWindow(i);
	GetDlgItem(IDC_C_HEX)->EnableWindow(i);
	GetDlgItem(IDC_B_DOT)->EnableWindow(i);
	GetDlgItem(IDC_B8)->EnableWindow(i);
	GetDlgItem(IDC_B9)->EnableWindow(i);
}

	//**HEXADECYMALNY**

void CkalkulatorMFCDlg::OnBnClickedCHex()
{
	Hex = !Hex;

	if (i == 0 && j == 1) {
		i = 1;
		j = 0;
	}
	else {
		i = 0;
		j = 1;
	}
	GetDlgItem(IDC_C_BIN)->EnableWindow(i);
	GetDlgItem(IDC_C_OCT)->EnableWindow(i);
	GetDlgItem(IDC_B_A)->EnableWindow(j);
	GetDlgItem(IDC_B_B)->EnableWindow(j);
	GetDlgItem(IDC_B_C)->EnableWindow(j);
	GetDlgItem(IDC_B_D)->EnableWindow(j);
	GetDlgItem(IDC_B_E)->EnableWindow(j);
	GetDlgItem(IDC_B_F)->EnableWindow(j);
	GetDlgItem(IDC_B_DOT)->EnableWindow(i);
}

 // **CYFRY** 

void CkalkulatorMFCDlg::OnBnClickedB0()
{
	if (Flag == true) {   // Flag odpowiada za to którą liczbę wpisujemy

		str1 += _T("0");   
		Edit_result = str1; // wyswietlamy wybrana cyfrę
	}
	else {
		str2 += _T("0");
		Edit_result = str2;
	}
	UpdateData(FALSE);   // "odświeżamy" wyświetlacz
}


void CkalkulatorMFCDlg::OnBnClickedB1()
{
	if (Flag == true) {

		str1 += _T("1");
		Edit_result = str1;
	}
	else {
		str2 += _T("1");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedB2()
{
	if (Flag == true) {

		str1 += _T("2");
		Edit_result = str1;
	}
	else {
		str2 += _T("2");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}

void CkalkulatorMFCDlg::OnBnClickedB3()
{
	if (Flag == true) {

		str1 += _T("3");
		Edit_result = str1;
	}
	else {
		str2 += _T("3");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedB4()
{
	if (Flag == true) {

		str1 += _T("4");
		Edit_result = str1;
	}
	else {
		str2 += _T("4");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}

void CkalkulatorMFCDlg::OnBnClickedB5()
{
	if (Flag == true) {

		str1 += _T("5");
		Edit_result = str1;
	}
	else {
		str2 += _T("5");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}

void CkalkulatorMFCDlg::OnBnClickedB6()
{
	if (Flag == true) {

		str1 += _T("6");
		Edit_result = str1;
	}
	else {
		str2 += _T("6");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedB7()
{
	if (Flag == true) {

		str1 += _T("7");
		Edit_result = str1;
	}
	else {
		str2 += _T("7");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedB8()
{
	if (Flag == true) {

		str1 += _T("8");
		Edit_result = str1;
	}
	else {
		str2 += _T("8");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedB9()
{
	if (Flag == true) {

		str1 += _T("9");
		Edit_result = str1;
	}
	else {
		str2 += _T("9");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


	// **LITERY**

void CkalkulatorMFCDlg::OnBnClickedBA()
{
	if (Flag == true) {

		str1 += _T("A");
		Edit_result = str1;
	}
	else {
		str2 += _T("A");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedBB()
{
	if (Flag == true) {

		str1 += _T("B");
		Edit_result = str1;
	}
	else {
		str2 += _T("B");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedBC()
{
	if (Flag == true) {

		str1 += _T("C");
		Edit_result = str1;
	}
	else {
		str2 += _T("C");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedBD()
{
	if (Flag == true) {

		str1 += _T("D");
		Edit_result = str1;
	}
	else {
		str2 += _T("D");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedBE()
{
	if (Flag == true) {

		str1 += _T("E");
		Edit_result = str1;
	}
	else {
		str2 += _T("E");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}


void CkalkulatorMFCDlg::OnBnClickedBF()
{
	if (Flag == true) {

		str1 += _T("F");
		Edit_result = str1;
	}
	else {
		str2 += _T("F");
		Edit_result = str2;
	}
	UpdateData(FALSE);
}

	// **DOT**

void CkalkulatorMFCDlg::OnBnClickedBDot()
{
	if (Flag == true) {

		str1 += _T(".");
		Edit_result = str1;
	}
	else {
		str2 += _T(".");
		Edit_result = str2;
	}
	UpdateData(FALSE);

}

														// ****OPERATORY DZIAŁAŃ**** //

// **DODAWANIE**

void CkalkulatorMFCDlg::OnBnClickedBPlus()
{
	
	if (Edit_result != _T("")) // jeśli na ekranie jest cokolwiek oprócz pustki...
	{
		if (Hex == true) {   // w zaleznosci od wybranego typu wpisywania (np. Hex), inaczej przekształcamy dane do dalszych obliczeń
			
			hextemp1 = Change.C_to_S(Edit_result);   // konwertujemy wpisane dane na string
		}
		else if (Bin == false && Hex == false && Oct == false ) {
			decimal1 = _ttof(Edit_result);   // konwertujemy wpisane dane na float
		}
		else {
			number1 = _wtoll(Edit_result);   // konwertujemy wpisane dane na long long
		}
		}
	Flag = !Flag;  // przestawiamy tryb na wpisywanie drugiej cyfry
	Edit_result = _T(""); // czyscimy ekran
	opera = 1;  // kazde dzialanie ma swoj opdowiednik opera - tutaj dodawanie -> 1

}

// **ODEJMOWANIE**

void CkalkulatorMFCDlg::OnBnClickedBMinus()
{
	if (Edit_result != _T("")) 
	{
		if (Hex == true) {

			hextemp1 = Change.C_to_S(Edit_result);
		}
		else if (Bin == false && Hex == false && Oct == false) {
			decimal1 = _ttof(Edit_result);
		}
		else {
			number1 = _wtoll(Edit_result);   
		}
	}
	Flag = !Flag;
	Edit_result = _T(""); 
	opera = 2;
}

// **MNOŻENIE**

void CkalkulatorMFCDlg::OnBnClickedBMult()
{
	if (Edit_result != _T("")) 
	{
		if (Hex == true) {

			hextemp1 = Change.C_to_S(Edit_result);
		}
		else if (Bin == false && Hex == false && Oct == false) {
			decimal1 = _ttof(Edit_result);
		}
		else {
			number1 = _wtoll(Edit_result);   
		}
	}
	Flag = !Flag;
	Edit_result = _T(""); 
	opera = 3;
}

// **DZIELENIE**

void CkalkulatorMFCDlg::OnBnClickedBDiv()
{
	if (Edit_result != _T("")) 
	{
		if (Hex == true) {

			hextemp1 = Change.C_to_S(Edit_result);
		}
		else if (Bin == false && Hex == false && Oct == false) {
			decimal1 = _ttof(Edit_result);
		}
		else {
			number1 = _wtoll(Edit_result);   
		}
	}
	Flag = !Flag;      
	Edit_result = _T(""); 
	opera = 4;
}

// **ZNAK RÓWNOŚCI**

void CkalkulatorMFCDlg::OnBnClickedBEq()
{
	if (Edit_result != _T("")) 
	{
		if (Hex == true) {
			hextemp2 = Change.C_to_S(Edit_result);
		}
		else if (Bin == false && Hex == false && Oct == false) {
			decimal2 = _ttof(Edit_result);
		}
		else {
			number2 = _wtoll(Edit_result);   
		}
		Flag = !Flag;  // przestawiamy na wpisywanie pierwszej liczby
	}


	switch (opera) {   // wybieranie odpowiedniej operacji
	case 1:
		if (Bin == true) {
			number0 = Change.bintodec(number1) + Change.bintodec(number2);  // działania wykonywane są na long long intach lub float...
			Edit_result.Format(_T("%lld"), Change.dectobin(number0)); // ....i przed wyswietleniem powracają do swoich oryginalnych postaci
		}
		else if (Oct == true) {
			number0 = Change.octtodec(number1) + Change.octtodec(number2);
			Edit_result.Format(_T("%lld"), Change.dectooct(number0));
		} 
		else if (Hex == true) {
			number0 = Change.hextodec(hextemp1) + Change.hextodec(hextemp2);
			Edit_result = Change.dectohex(number0);
		}
		else{
			decimal0 = decimal1 + decimal2;
			Edit_result.Format(_T("%.3f"), decimal0);
		}
		break;
	case 2:
		if (Bin == true) {
			number0 = Change.bintodec(number1) - Change.bintodec(number2);
			Edit_result.Format(_T("%lld"), Change.dectobin(number0));
		}
		else if (Oct == true) {
			number0 = Change.octtodec(number1) - Change.octtodec(number2);
			Edit_result.Format(_T("%lld"), Change.dectooct(number0));
		}
		else if (Hex == true) {
			number0 = Change.hextodec(hextemp1) - Change.hextodec(hextemp2);
			Edit_result = Change.dectohex(number0);
		}
		else {
			decimal0 = decimal1 - decimal2;
			Edit_result.Format(_T("%.3f"), decimal0);
		}
		break;
	case 3:
		if (Bin == true) {
			number0 = Change.bintodec(number1) * Change.bintodec(number2);
			Edit_result.Format(_T("%lld"), Change.dectobin(number0));
		}
		else if (Oct == true) {
			number0 = Change.octtodec(number1) * Change.octtodec(number2);
			Edit_result.Format(_T("%lld"), Change.dectooct(number0));
		}
		else if (Hex == true) {
			number0 = Change.hextodec(hextemp1) * Change.hextodec(hextemp2);
			Edit_result = Change.dectohex(number0);
		}
		else {
			decimal0 = decimal1 * decimal2;
			Edit_result.Format(_T("%.3f"), decimal0);
		}
		break;
	case 4:
		if (Bin == true) {
			number0 = Change.bintodec(number1) / Change.bintodec(number2);
			Edit_result.Format(_T("%lld"), Change.dectobin(number0));
		}
		else if (Oct == true) {
			number0 = Change.octtodec(number1) / Change.octtodec(number2);
			Edit_result.Format(_T("%lld"), Change.dectooct(number0));
		}
		else if (Hex == true) {
			number0 = Change.hextodec(hextemp1) / Change.hextodec(hextemp2);
			Edit_result = Change.dectohex(number0);
		}
		else if (decimal2 != 0){
			decimal0 = decimal1 / decimal2;
			Edit_result.Format(_T("%.3f"), decimal0);
		}
		else {
			Edit_result = _T("CAN'T DIVIDE BY 0!!!");
		}
		break;
	}
	UpdateData(FALSE);
	str1 = str2 = _T("");
}


	// **CZYSZCZENIE EKRANU**
void CkalkulatorMFCDlg::OnBnClickedBDelete()
{
	number0, number1, number2 = 0;
	str1 = str2 = _T("");
	Edit_result = _T("");
	Flag = true;
	UpdateData(FALSE);
}




