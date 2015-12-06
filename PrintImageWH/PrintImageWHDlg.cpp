
// PrintImageWHDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "PrintImageWH.h"
#include "PrintImageWHDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CPrintImageWHDlg 대화 상자



CPrintImageWHDlg::CPrintImageWHDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRINTIMAGEWH_DIALOG, pParent)
	, status(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrintImageWHDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_imgList, imgList);
	DDX_Text(pDX, IDC_EDIT1, status);
}

BEGIN_MESSAGE_MAP(CPrintImageWHDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FileOpen, &CPrintImageWHDlg::OnBnClickedFileopen)
	ON_BN_CLICKED(IDC_BtnGetWH, &CPrintImageWHDlg::OnBnClickedBtngetwh)
	ON_BN_CLICKED(IDC_BtnReset, &CPrintImageWHDlg::OnBnClickedBtnreset)
	ON_BN_CLICKED(IDC_Positive, &CPrintImageWHDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_Negative, &CPrintImageWHDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CPrintImageWHDlg 메시지 처리기

BOOL CPrintImageWHDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	ShowWindow(SW_MINIMIZE);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CButton* pButton = (CButton*)GetDlgItem(IDC_Positive);
	pButton->SetCheck(TRUE);
	chk = 1;


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPrintImageWHDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPrintImageWHDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		status = "READY";
		UpdateData(FALSE); // 변수 값을 컨트롤로
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPrintImageWHDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPrintImageWHDlg::OnBnClickedFileopen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_EXPLORER, _T("Image(*.BMP,*.JPG, *JPEG, *.PNG)|*.BMP;*.JPG;*.JPEG;*.PNG|All Files(*.*)|*.*||"));
	CString File;
	CString strFileList;

	const int c_cMaxFiles = 2000 /*선택할 파일 숫자*/;	// 메모리 부족현상으로 확장 안해주면 몇개 못씀
	const int c_cbBuffSize = (c_cMaxFiles * (MAX_PATH + 1)) + 1;
	dlg.GetOFN().lpstrFile = strFileList.GetBuffer(c_cbBuffSize);
	dlg.GetOFN().nMaxFile = c_cbBuffSize;

	if (IDOK == dlg.DoModal())
	{
		CString strPathName = dlg.GetPathName();
		TRACE("name = %s\n", strPathName);
		POSITION pos = dlg.GetStartPosition();

		for (POSITION pos = dlg.GetStartPosition(); pos != NULL;)
		{
			File = dlg.GetNextPathName(pos);
			imgList.AddString(File);
		}
	}
}

string CPrintImageWHDlg::CStrToStr(CString str)
{
	string outputStr = string(CT2CA(str.operator LPCWSTR()));
	return outputStr;
}


void CPrintImageWHDlg::OnBnClickedBtngetwh()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	FILE * file;
	CString locImg;
	Mat temp;
	int width, height;

	switch (chk)
	{
	case 1:
	{
		if ((file = fopen("positives.txt", "wt")) != NULL)
		{
			status = "Processing";
			UpdateData(FALSE); // 변수 값을 컨트롤로

			for (int i = 0; i < imgList.GetCount(); i++)
			{
				imgList.GetText(i, locImg);
				temp = imread(CStrToStr(locImg));

				width = temp.cols;
				height = temp.rows;

				char strTemp[1000];
				sprintf(strTemp, "%s ", CStrToStr(locImg));
				fputs(strTemp, file);
				fputs("1 0 0 ", file);
				sprintf(strTemp, "%d ", width);
				fputs(strTemp, file);
				sprintf(strTemp, "%d\n", height);
				fputs(strTemp, file);
			}

			status = "Done";
			UpdateData(FALSE); // 변수 값을 컨트롤로
			fclose(file);
		}

		if (file == NULL)
		{
			cout << "file open error!\n" << endl;
		}
	}
	break;
	case 2:
	{
	if ((file = fopen("negatives.txt", "wt")) != NULL)
	{
		status = "Processing";
		UpdateData(FALSE); // 변수 값을 컨트롤로

		for (int i = 0; i < imgList.GetCount(); i++)
		{
			imgList.GetText(i, locImg);
			temp = imread(CStrToStr(locImg));

			width = temp.cols;
			height = temp.rows;

			char strTemp[1000];
			sprintf(strTemp, "%s ", CStrToStr(locImg));
			fputs(strTemp, file);
			fputs("\n", file);
		}

		status = "Done";
		UpdateData(FALSE); // 변수 값을 컨트롤로
		fclose(file);
	}

	if (file == NULL)
	{
		cout << "file open error!\n" << endl;
	}
	}
	break;
	default:
		break;
	}
}


void CPrintImageWHDlg::OnBnClickedBtnreset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	imgList.ResetContent();
}


void CPrintImageWHDlg::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CButton* pButton = (CButton*)GetDlgItem(IDC_Positive);
	pButton->SetCheck(TRUE);
	chk = 1;
}


void CPrintImageWHDlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CButton* pButton = (CButton*)GetDlgItem(IDC_Negative);
	pButton->SetCheck(TRUE);
	chk = 2;
}
