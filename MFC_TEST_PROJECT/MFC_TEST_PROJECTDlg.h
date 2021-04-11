
// MFC_TEST_PROJECTDlg.h: 헤더 파일
//
#pragma once

#include <vector>

#include <d2d1.h>
#include <d2d1_1helper.h>

#pragma comment(lib, "d2d1.lib")
// CMFCTESTPROJECTDlg 대화 상자
class CMFCTESTPROJECTDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCTESTPROJECTDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_TEST_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


private:
	std::vector<CPoint> rect_start_pos; //마우스가 클릭되었을때 좌표를 저장할 변수 
	CPoint mouse_point;

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
	ID2D1Factory* g_ipD2Factory = nullptr; //초반에만 초기화 하는 내역


	ID2D1HwndRenderTarget* g_ipRenderTarget = nullptr; //계속 생성되는 객체
	//CDCRenderTarget * g_ipRenderTarget = nullptr; //계속 생성되는 객체
//	CD2DSolidColorBrush *m_pPlackBrush;

	HWND hWnd;

	HRESULT CreateDeviceIndependentResources();
	HRESULT CreateDeviceResources();

	void OnPaintRenderTarget();
	void OnCreatRenderTarget(HWND hWnd);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

public:

	void MouseMovingPoint(CPoint point);
	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
};
  