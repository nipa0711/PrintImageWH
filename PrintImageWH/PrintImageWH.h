
// PrintImageWH.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include <opencv2\opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;


// CPrintImageWHApp:
// �� Ŭ������ ������ ���ؼ��� PrintImageWH.cpp�� �����Ͻʽÿ�.
//

class CPrintImageWHApp : public CWinApp
{
public:
	CPrintImageWHApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPrintImageWHApp theApp;