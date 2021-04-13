
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
	OnCreatRenderTarget(GetSafeHwnd());
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
void CMFCTESTPROJECTDlg::OnPaint() //그림을 유지합니다.
{
	//갯수가 하나도없는 경우 return 합니다
	if (rect_pos.size() == 0)
	{
		return;
	}


	//g_ipRenderTarget->BeginDraw();

	//if (rect_pos.size() == 1) //선택했던 점이 하나인경우
	//{
	//	g_ipRenderTarget->Clear(D2D1::ColorF(0.0f, 0.8f, 1.0f)); //도면 영역을 지정된 색상으로 지웁니다.

	//	D2D1_ELLIPSE my_region;
	//	my_region.point.x = rect_pos[0].x; //x위치
	//	my_region.point.y = rect_pos[0].y;//y 위치
	//	my_region.radiusX = 5.0f; //넓이 반지름
	//	my_region.radiusY = 5.0f; //높이 반지름

	//	ID2D1SolidColorBrush* p_yellow_brush = NULL;
	//	g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 0.0f), &p_yellow_brush);

	//	g_ipRenderTarget->FillEllipse(my_region, p_yellow_brush);

	//	p_yellow_brush->Release();
	//	p_yellow_brush = nullptr;
	//}
	//else if (rect_pos.size() > 1)
	//{
	//	for (int i = 1; i < rect_pos.size(); i++)
	//	{
	//		g_ipRenderTarget->Clear(D2D1::ColorF(0.0f, 0.8f, 1.0f)); //도면 영역을 지정된 색상으로 지웁니다.

	//		D2D1_ELLIPSE my_region;
	//		my_region.point.x = rect_pos[i].x; //x위치
	//		my_region.point.y = rect_pos[i].y;//y 위치
	//		my_region.radiusX = 5.0f; //넓이 반지름
	//		my_region.radiusY = 5.0f; //높이 반지름

	//		ID2D1SolidColorBrush* p_yellow_brush = NULL;
	//		g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 0.0f), &p_yellow_brush);

	//		g_ipRenderTarget->FillEllipse(my_region, p_yellow_brush);

	//		p_yellow_brush->Release();
	//		p_yellow_brush = nullptr;
	//	}
	//}

	//g_ipRenderTarget->EndDraw();


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
	rect_pos.push_back(point);

	//rect_start_pos.push_back(point);
	CDialogEx::OnLButtonDown(nFlags, point);
}

//화면에 버튼을 클릭하고 놓았을때의 이벤트
//void CMFCTESTPROJECTDlg::OnLButtonUp(UINT nFlags, CPoint point) //실시간으로 그리진않습니다.
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	//rect_start_pos.pop_back();
//	if (rect_pos.size()==0)
//	{
//		return;
//	}
//	rect_pos.pop_back();
//
//	CDialogEx::OnLButtonUp(nFlags, point);
//}

//다이렉트 2D로 선그리기(실시간 선그리기)
void CMFCTESTPROJECTDlg::OnMouseMove(UINT nFlags, CPoint point)
{

	if (rect_pos.size() == 0)
	{
		return;
	}

	g_ipRenderTarget->BeginDraw();
	g_ipRenderTarget->Clear(D2D1::ColorF(0.0f, 0.8f, 1.0f)); //도면 영역을 지정된 색상으로 지웁니다.

	if (rect_pos.size() == 1)
	{

		D2D1_ELLIPSE my_region;


		my_region.point.x = rect_pos[0].x; //x위치
		my_region.point.y = rect_pos[0].y;//y 위치
		my_region.radiusX = 5.0f; //넓이 반지름
		my_region.radiusY = 5.0f; //높이 반지름

		ID2D1SolidColorBrush* p_yellow_brush = NULL;
		g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 0.0f), &p_yellow_brush);

		g_ipRenderTarget->FillEllipse(my_region, p_yellow_brush);

		p_yellow_brush->Release();
		p_yellow_brush = nullptr;

		ID2D1SolidColorBrush* p_black_brush = nullptr;
		g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.0f, 0.0f), &p_black_brush);
		//가장 처음의 위치를 불러와서 첫 위치를 지정해줍니다
		g_ipRenderTarget->DrawLine(D2D1::Point2F(rect_pos[0].x, rect_pos[0].y), D2D1::Point2F(point.x, point.y), p_black_brush, 0.50f);

	}
	else if (rect_pos.size() > 1)
	{
		for (int i = 0; i < rect_pos.size() - 1; i++)
		{
			D2D1_ELLIPSE my_region;
			my_region.point.x = rect_pos[i].x; //x위치
			my_region.point.y = rect_pos[i].y;//y 위치
			my_region.radiusX = 5.0f; //넓이 반지름
			my_region.radiusY = 5.0f; //높이 반지름

			ID2D1SolidColorBrush* p_yellow_brush = NULL;
			g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 0.0f), &p_yellow_brush);

			g_ipRenderTarget->FillEllipse(my_region, p_yellow_brush);

			p_yellow_brush->Release();
			p_yellow_brush = nullptr;

			ID2D1SolidColorBrush* p_black_brush = nullptr;
			g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.0f, 0.0f), &p_black_brush);

			//가장 처음의 위치를 불러와서 첫 위치를 지정해줍니다
			g_ipRenderTarget->DrawLine(D2D1::Point2F(rect_pos[i].x, rect_pos[i].y), D2D1::Point2F(rect_pos[i + 1].x, rect_pos[i + 1].y), p_black_brush, 0.50f);
		}


		D2D1_ELLIPSE my_region;
		my_region.point.x = rect_pos[rect_pos.size() - 1].x; //x위치
		my_region.point.y = rect_pos[rect_pos.size() - 1].y;//y 위치
		my_region.radiusX = 5.0f; //넓이 반지름
		my_region.radiusY = 5.0f; //높이 반지름

		ID2D1SolidColorBrush* p_yellow_brush = NULL;
		g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 0.0f), &p_yellow_brush);

		g_ipRenderTarget->FillEllipse(my_region, p_yellow_brush);

		p_yellow_brush->Release();
		p_yellow_brush = nullptr;

		ID2D1SolidColorBrush* p_black_brush = nullptr;
		g_ipRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.0f, 0.0f), &p_black_brush);

		//가장 처음의 위치를 불러와서 첫 위치를 지정해줍니다
		g_ipRenderTarget->DrawLine(D2D1::Point2F(rect_pos[rect_pos.size() - 1].x, rect_pos[rect_pos.size() - 1].y), D2D1::Point2F(point.x, point.y), p_black_brush, 0.50f);

	}

	g_ipRenderTarget->EndDraw();

	CDialogEx::OnMouseMove(nFlags, point);
}



//
//HRESULT CMFCTESTPROJECTDlg::CreateDeviceIndependentResources()  //factory 를 초기화합니다.
//{
//	HRESULT hr = S_OK;
//
//	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &g_ipD2Factory);
//	return hr;
//}

//
//HRESULT CMFCTESTPROJECTDlg::CreateDeviceResources()  //factory 를 초기화합니다.
//{
//	HRESULT hr = S_OK;
//
//	if (!g_ipRenderTarget)
//	{
//		RECT rc;
//		GetClientRect(&rc);
//
//		D2D1_SIZE_U size = D2D1::SizeU(
//			rc.right - rc.left,
//			rc.bottom - rc.top
//		);
//		/*
//				hr = g_ipD2Factory->CreateHwndRenderTarget(
//					D2D1::RenderTargetProperties(),
//					D2D1::HwndRenderTargetProperties(hWnd, size),
//					&g_ipRenderTarget
//				);
//		*/
//		hr = g_ipD2Factory->CreateHwndRenderTarget(
//			D2D1::RenderTargetProperties(),
//			D2D1::HwndRenderTargetProperties(hWnd, size),
//			&g_ipRenderTarget
//		);
//
//
//	}
//	return hr;
//}
//




void CMFCTESTPROJECTDlg::OnCreatRenderTarget(HWND hWnd)
{
	HRESULT hr;
	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &g_ipD2Factory);
	RECT r;
	GetClientRect(&r);

	g_ipD2Factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(r.right, r.bottom)),
		&g_ipRenderTarget);

}
