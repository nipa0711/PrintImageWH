
// PrintImageWHDlg.h : ��� ����
//

#pragma once
#pragma warning(disable:4996)
#include "afxwin.h"


// CPrintImageWHDlg ��ȭ ����
class CPrintImageWHDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPrintImageWHDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRINTIMAGEWH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFileopen();
	CListBox imgList;
	afx_msg void OnBnClickedBtngetwh();
	string CStrToStr(CString str);
	afx_msg void OnBnClickedBtnreset();
	afx_msg void OnBnClickedRadio1();
	int chk;
	afx_msg void OnBnClickedRadio2();
	CString status;
};
