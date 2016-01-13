
// calculatorDlg.h : 头文件
//

#pragma once


// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数
	

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	int c1,c2,c3;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked10();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedReduce();
	afx_msg void OnBnClickedRide();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedCalculator();
	int flag;
	double temp;
	afx_msg void OnBnClickedEliminate();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedDeleteback();
	afx_msg void OnBnClickedOpposite();
	afx_msg void OnBnClickedReciprocal();
	afx_msg void OnBnClickedSquareroot();
	afx_msg void OnBnClickedOpposite3();
	afx_msg void OnBnClickedSin();
	afx_msg void OnBnClickedCos();
	afx_msg void OnBnClickedTan();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	double secondag;
	double minuteag;
	double hourag;
    double x,y;
	int m_h;
	int m_m;
	int m_s;
	afx_msg void OnBnClickedStare();
};
