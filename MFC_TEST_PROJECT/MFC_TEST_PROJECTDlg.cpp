
// MFC_TEST_PROJECTDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_TEST_PROJECT.h"
#include "MFC_TEST_PROJECTDlg.h"
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


// CMFCTESTPROJECTDlg 대화 상자



CMFCTESTPROJECTDlg::CMFCTESTPROJECTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_TEST_PROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	HRESULT hr = CreateDeviceIndependentResources();

	if (SUCCEEDED(hr))
	{

	}


	//hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &g_ipD2Factory);


	//assert(hr == S_OK);

}


void CMFCTESTPROJECTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCTESTPROJECTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CMFCTESTPROJECTDlg 메시지 처리기


BOOL CMFCTESTPROJECTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCTESTPROJECTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//
void CMFCTESTPROJECTDlg::OnPaint()
{
	CPaintDC dc(this);
	CString str;
	str.Format(_T("X=%d, Y= %d"), mouse_point, mouse_point.y);
	dc.TextOut(mouse_point.x, mouse_point.y, str);

	MouseMovingPoint(mouse_point); //마우스의 위치를 계속 화면에 표출합니다.


	g_ipRenderTarget->BeginDraw();
	g_ipRenderTarget->Clear(D2D1::ColorF(0.0f, 0.8f, 1.0f)); //도면 영역을 지정된 색상으로 지웁니다.

	D2D1_ELLIPSE my_region;
	my_region.point.x = mouse_point.x; //x위치
	my_region.point.y = mouse_point.y;//y 위치
	my_region.radiusX = 50.0f; //넓이 반지름
	my_region.radiusY = 15.0f; //높이 반지름

	ID2D1SolidColorBrush* p_yellow_brush = NULL;
	g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 0.0f), &p_yellow_brush);

	g_ipRenderTarget->FillEllipse(my_region, p_yellow_brush);

	p_yellow_brush->Release();
	p_yellow_brush = nullptr;


	g_ipRenderTarget->EndDraw();





	/*HRESULT hr = S_OK;
	hr = CreateDeviceResources();*/


	//if (SUCCEEDED(hr))
	//{
	//	g_ipRenderTarget->BeginDraw();

	//	g_ipRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	//	CD2DPointF d2dStartPoint;
	//	d2dStartPoint.x = mouse_point.x;
	//	d2dStartPoint.y = mouse_point.y;
	//	double radius =20.0f;
	//	D2D1_ELLIPSE ellipse = D2D1::Ellipse(d2dStartPoint, (FLOAT)radius, (FLOAT)radius);	//거리를 반지름으로 가지는 원을 그립니다

	//	ID2D1SolidColorBrush *p_yellow_brush = NULL;
	//	// 원을 그리는데 사용할 Brush 객체를 노란색으로 생성한다. 
	//	g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 0.0f), &p_yellow_brush);

	//	g_ipRenderTarget->FillEllipse(ellipse, p_yellow_brush);
	//}

	CDialogEx::OnPaint();

}





// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCTESTPROJECTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//화면에 버튼을 클릭했을 때의 이벤트
//점을찍습니다.

void CMFCTESTPROJECTDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.


	//rect_start_pos.push_back(point);
	CDialogEx::OnLButtonDown(nFlags, point);
}

//화면에 버튼을 클릭하고 놓았을때의 이벤트
void CMFCTESTPROJECTDlg::OnLButtonUp(UINT nFlags, CPoint point) //실시간으로 그리진않습니다.
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//rect_start_pos.pop_back();
	CDialogEx::OnLButtonUp(nFlags, point);
}

//다이렉트 2D로 선그리기(실시간 선그리기)
void CMFCTESTPROJECTDlg::OnMouseMove(UINT nFlags, CPoint point)
{

	mouse_point = point;
	MouseMovingPoint(mouse_point); //마우스의 위치를 계속 화면에 표출합니다.


	g_ipRenderTarget->BeginDraw();
	g_ipRenderTarget->Clear(D2D1::ColorF(0.0f, 0.8f, 1.0f)); //도면 영역을 지정된 색상으로 지웁니다.

	D2D1_ELLIPSE my_region;
	my_region.point.x = mouse_point.x; //x위치
	my_region.point.y = mouse_point.y;//y 위치
	my_region.radiusX = 50.0f; //넓이 반지름
	my_region.radiusY = 15.0f; //높이 반지름

	ID2D1SolidColorBrush* p_yellow_brush = NULL;
	g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 0.0f), &p_yellow_brush);

	g_ipRenderTarget->FillEllipse(my_region, p_yellow_brush);

	p_yellow_brush->Release();
	p_yellow_brush = nullptr;


	g_ipRenderTarget->EndDraw();


	CDialogEx::OnMouseMove(nFlags, point);
}

//마우스를 따라다니는 글자를 그립니다.
void CMFCTESTPROJECTDlg::MouseMovingPoint(CPoint point)
{
	//화면에 좌표 그리는 부분은 계속 그리도록 합니다.
	//mouse_point = point;

	CClientDC dc(this);
	CPen my_pen(PS_SOLID, 5, RGB(0, 0, 255));
	dc.SelectObject(&my_pen);
	SelectObject(dc, GetStockObject(NULL_BRUSH)); //펜을 설정합니다.
}


HRESULT CMFCTESTPROJECTDlg::CreateDeviceIndependentResources()  //factory 를 초기화합니다.
{
	HRESULT hr = S_OK;

	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &g_ipD2Factory);
	return hr;
}


HRESULT CMFCTESTPROJECTDlg::CreateDeviceResources()  //factory 를 초기화합니다.
{
	HRESULT hr = S_OK;

	if (!g_ipRenderTarget)
	{
		RECT rc;
		GetClientRect(&rc);

		D2D1_SIZE_U size = D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top
		);
/*
		hr = g_ipD2Factory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hWnd, size),
			&g_ipRenderTarget
		);
*/
		hr = g_ipD2Factory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hWnd, size),
			&g_ipRenderTarget
		);


	}



	return hr;
}


//이벤트를 따로 해주지않아도 여기에 이벤트를 하면 이쪽으로 넘어옵니다.
BOOL CMFCTESTPROJECTDlg::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	switch (message)
	{
	case WM_CREATE:
		OnCreatRenderTarget(GetSafeHwnd());
		break;
	case WM_PAINT:
		break;
	case WM_RBUTTONDOWN:
		break;

	default:
		break;
	}
	return CDialogEx::OnWndMsg(message, wParam, lParam, pResult);
}



void CMFCTESTPROJECTDlg::OnCreatRenderTarget(HWND hWnd)
{
	RECT r;
	GetClientRect(&r);

	g_ipD2Factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(r.right, r.bottom)),
		&g_ipRenderTarget);

}
