
// BuildMFCDlg.h : header file
//

#pragma once

// GuiLite interface
typedef struct
{
	unsigned int dwMsgId;
	unsigned int dwParam1;
	unsigned int dwParam2;
}OUTMSGINFO;

extern int startHostMonitor(int main_cnt, int main_width, int main_height, int sub_cnt, int sub_width, int sub_height, int color_bytes);
extern void* getUiOfHostMonitor(int display_id, int* width, int* height);
extern int sendTouch2HostMonitor(void* buf, int len, int display_id);

// CBuildMFCDlg dialog
class CBuildMFCDlg : public CDialogEx
{
// Construction
public:
	CBuildMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUILDMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

private:
	void renderUI();
	CPoint pointMFC2GuiLite(CPoint point);
	static CBuildMFCDlg* m_the_dialog;
	int m_ui_width;
	int m_ui_height;
	BITMAPINFO m_ui_bm_info;
	bool m_is_mouse_down;
	static UINT ThreadHostMonitor(LPVOID pParam);
	static UINT ThreadRefreshUI(LPVOID pParam);
};
