
// calculatorDlg.cpp : 实现文件


#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "stdio.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CcalculatorDlg 对话框




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
	, m_h(0)
	, m_m(0)
	, m_s(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	temp=0;
	flag=10;
	
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Text(pDX, IDC_EDIT2, m_h);
	DDX_Text(pDX, IDC_EDIT3, m_m);
	DDX_Text(pDX, IDC_EDIT4, m_s);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_10, &CcalculatorDlg::OnBnClicked10)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_REDUCE, &CcalculatorDlg::OnBnClickedReduce)
	ON_BN_CLICKED(IDC_RIDE, &CcalculatorDlg::OnBnClickedRide)
	ON_BN_CLICKED(IDC_DIVIDE, &CcalculatorDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_CALCULATOR, &CcalculatorDlg::OnBnClickedCalculator)
	ON_BN_CLICKED(IDC_ELIMINATE, &CcalculatorDlg::OnBnClickedEliminate)
	ON_BN_CLICKED(IDC_CLEAR, &CcalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_DELETEBACK, &CcalculatorDlg::OnBnClickedDeleteback)
	ON_BN_CLICKED(IDC_OPPOSITE, &CcalculatorDlg::OnBnClickedOpposite)
	ON_BN_CLICKED(IDC_RECIPROCAL, &CcalculatorDlg::OnBnClickedReciprocal)
	ON_BN_CLICKED(IDC_SQUAREROOT, &CcalculatorDlg::OnBnClickedSquareroot)
	ON_BN_CLICKED(IDC_OPPOSITE3, &CcalculatorDlg::OnBnClickedOpposite3)
	ON_BN_CLICKED(IDC_SIN, &CcalculatorDlg::OnBnClickedSin)
	ON_BN_CLICKED(IDC_COS, &CcalculatorDlg::OnBnClickedCos)
	ON_BN_CLICKED(IDC_TAN, &CcalculatorDlg::OnBnClickedTan)
	
//	ON_WM_TIMER()
ON_WM_TIMER()
ON_BN_CLICKED(IDC_STARE, &CcalculatorDlg::OnBnClickedStare)
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,1000,NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE                                                                                 
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked10()//.
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L".";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedReduce()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedRide()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDivide()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedCalculator()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE(L"flag=%d",flag);
	UpdateData(true);
	if
		(flag==1)
	{
		temp=temp+_ttof(m_str);
	}
	if
		(flag==2)
	{
		temp=temp-_ttof(m_str);
	}
	if
		(flag==3)
	{
		temp=temp*_ttof(m_str);
	}
	if
		(flag==4)


	    {

		    if(_ttof(m_str)==0)

		        {m_str.Format(L"除数不能为0");}

		    else
			{
					temp=temp/_ttof(m_str);
					m_str.Format(L"%lf",temp);
			}
	    }
		
	
	if(flag==10)
	{
		temp=_ttof(m_str);

	}
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	


}

void CcalculatorDlg::OnBnClickedEliminate()
{
	// TODO: 在此添加控件通知处理程序代码全部删除
	UpdateData(true);
	flag=0;
	m_str="";
	UpdateData(false);


}


void CcalculatorDlg::OnBnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码把新增上的删除了,但是什么运算符号不删除
	UpdateData(true);
	m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedDeleteback()
{
	// TODO: 在此添加控件通知处理程序代码只删除最后一位
	UpdateData(true);
	m_str="";
	UpdateData(false);
}
void CcalculatorDlg::OnBnClickedOpposite()
{
	// TODO: 在此添加控件通知处理程序代码取相反数
	double temp1;
	UpdateData(true);
	temp1=_ttof(m_str);
	temp1=-temp1;
	m_str.Format(L"%lf",temp1);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);


}


void CcalculatorDlg::OnBnClickedReciprocal()
{
	// TODO: 在此添加控件通知处理程序代码倒数
	double temp2;
	UpdateData(true);
	temp2=_ttof(m_str);
	if(temp2==0)
	{
		m_str.Format(L"除数不能为0");
	}
	else
	{
		temp2=1/temp2;
		m_str.Format(L"%lf",temp2);
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedSquareroot()
{
	// TODO: 在此添加控件通知处理程序代码开方
	double temp3;
	UpdateData(true);
	temp3=_ttof(m_str);
	temp3=sqrt(temp3);
	m_str.Format(L"%lf",temp3);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	}

	


void CcalculatorDlg::OnBnClickedOpposite3()
{
	// TODO: 在此添加控件通知处理程序代码百分号
	double temp4;
	UpdateData(true);
	temp4=_ttof(m_str);
	temp4=temp4/100;
	m_str.Format(L"%lf",temp4);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	}



void CcalculatorDlg::OnBnClickedSin()
{
	// TODO: 在此添加控件通知处理程序代码sin
	double temp5;
	UpdateData(true);
	temp5=_ttof(m_str);
	temp5=sin(temp5);
	m_str.Format(L"%lf",temp5);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}



void CcalculatorDlg::OnBnClickedCos()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp6;
	UpdateData(true);
	temp6=_ttof(m_str);
	temp6=cos(temp6);
	m_str.Format(L"%lf",temp6);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	
}


void CcalculatorDlg::OnBnClickedTan()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp7;
	UpdateData(true);
	temp7=_ttof(m_str);
	temp7=tan(temp7);
	m_str.Format(L"%lf",temp7);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	


}


void CcalculatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pdc;
	pdc=GetDC();
	pdc->SetWindowOrg(-888,-184);
	pdc->Ellipse(-100,100,100,-100);
	CPen pen(PS_SOLID,3,RGB(0,0,0));
	pdc->TextOutW(85,-8,L"III");
	pdc->TextOutW(-98,-8,L"IX");
	pdc->TextOutW(-8,-99,L"XII ");
	pdc->TextOutW(-2,83,L"VI");
	for(int i=0;i<12;i++)
	{
		double l=90,ag=i*3.1415926/6;
		double a=l*sin(ag)+2,b=-l*cos(ag)+2,c=l*sin(ag)-2,d=-l*cos(ag)-2;
		pdc->Ellipse(a,b,c,d); 
	}
	CPen deletepen(PS_SOLID,6,RGB(255,255,255));
	CPen *oldpen;
   
	
	int rsecond=85; 
	oldpen=pdc->SelectObject(&deletepen); 
	CPen secondpen(PS_SOLID,3,RGB(255,0,0)); 
	oldpen=pdc->SelectObject(&secondpen);
	secondag=secondag+3.1415926/30;
	x=rsecond*sin(secondag);
	y=-rsecond*cos(secondag);
	pdc->MoveTo(0,0); 
	pdc->LineTo(x,y);



	int rminute=60; 
	oldpen=pdc->SelectObject(&deletepen); 
	CPen minutepen(PS_SOLID,5,RGB(150,150,150)); 
	oldpen=pdc->SelectObject(&minutepen);
	minuteag=minuteag+3.1415926/1800;
	x=rminute*sin(minuteag);
	y=-rminute*cos(minuteag);
	pdc->MoveTo(0,0); 
	pdc->LineTo(x,y);
	   


	int rhour=35; 
	oldpen=pdc->SelectObject(&deletepen); 
	CPen hourpen(PS_SOLID,5,RGB(0,150,150)); 
	oldpen=pdc->SelectObject(&hourpen);
	hourag=hourag+3.1415926/21600;
	x=rhour*sin(hourag);
	y=-rhour*cos(hourag);
	pdc->MoveTo(0,0); 
	pdc->LineTo(x,y);
	CDialogEx::OnTimer(nIDEvent);
}


void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
		TRACE("X=%d,Y=%d\n",point.x,point.y);
	CDialogEx::OnMouseMove(nFlags, point);
}


void CcalculatorDlg::OnBnClickedStare()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_h>=12)
		m_h=m_h-12;
	hourag=m_h*(3.1415926/6)+m_m*(3.1415926/360)+m_s*(3.1415926/21600);
	minuteag=m_m*(3.1415926/30)+m_s*(3.1415926/1800);
	secondag=m_s*(3.1415926/30);
	SetTimer(1,1000,NULL);
}
