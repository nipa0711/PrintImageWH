
// PrintImageWHDlg.h : 헤더 파일
//

#pragma once
#pragma warning(disable:4996)
#include "afxwin.h"


// CPrintImageWHDlg 대화 상자
class CPrintImageWHDlg : public CDialogEx
{
// 생성입니다.
public:
	CPrintImageWHDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRINTIMAGEWH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
