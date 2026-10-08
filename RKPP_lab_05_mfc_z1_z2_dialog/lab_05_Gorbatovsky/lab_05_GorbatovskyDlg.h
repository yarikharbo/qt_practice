
// lab_05_GorbatovskyDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно Clab05GorbatovskyDlg
class Clab05GorbatovskyDlg : public CDialogEx
{
// Создание
public:
	Clab05GorbatovskyDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB_05_GORBATOVSKY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
};
