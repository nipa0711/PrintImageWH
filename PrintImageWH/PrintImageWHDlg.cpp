
// PrintImageWHDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "PrintImageWH.h"
#include "PrintImageWHDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CPrintImageWHDlg ��ȭ ����



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


// CPrintImageWHDlg �޽��� ó����

BOOL CPrintImageWHDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	ShowWindow(SW_MINIMIZE);

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CButton* pButton = (CButton*)GetDlgItem(IDC_Positive);
	pButton->SetCheck(TRUE);
	chk = 1;


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CPrintImageWHDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		status = "READY";
		UpdateData(FALSE); // ���� ���� ��Ʈ�ѷ�
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CPrintImageWHDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPrintImageWHDlg::OnBnClickedFileopen()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_EXPLORER, _T("Image(*.BMP,*.JPG, *JPEG, *.PNG)|*.BMP;*.JPG;*.JPEG;*.PNG|All Files(*.*)|*.*||"));
	CString File;
	CString strFileList;

	const int c_cMaxFiles = 2000 /*������ ���� ����*/;	// �޸� ������������ Ȯ�� �����ָ� � ����
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
			UpdateData(FALSE); // ���� ���� ��Ʈ�ѷ�

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
			UpdateData(FALSE); // ���� ���� ��Ʈ�ѷ�
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
		UpdateData(FALSE); // ���� ���� ��Ʈ�ѷ�

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
		UpdateData(FALSE); // ���� ���� ��Ʈ�ѷ�
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	imgList.ResetContent();
}


void CPrintImageWHDlg::OnBnClickedRadio1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CButton* pButton = (CButton*)GetDlgItem(IDC_Positive);
	pButton->SetCheck(TRUE);
	chk = 1;
}


void CPrintImageWHDlg::OnBnClickedRadio2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CButton* pButton = (CButton*)GetDlgItem(IDC_Negative);
	pButton->SetCheck(TRUE);
	chk = 2;
}
