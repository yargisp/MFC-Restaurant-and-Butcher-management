// AboutDLG.cpp : implementation file
//

#include "pch.h"
#include "MFC_Final_Project_Rest_Update.h"
#include "AboutDLG.h"
#include "afxdialogex.h"


// AboutDLG dialog

IMPLEMENT_DYNAMIC(AboutDLG, CDialogEx)

AboutDLG::AboutDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

AboutDLG::~AboutDLG()
{
}

void AboutDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AboutDLG, CDialogEx)
END_MESSAGE_MAP()


// AboutDLG message handlers
