; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgJiSuanQi
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Exercise.h"
LastPage=0

ClassCount=7
Class1=CExerciseApp
Class2=CExerciseDoc
Class3=CExerciseView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_JiSuan
Class6=CDlgJiSuanQi
Resource3=IDD_ABOUTBOX
Class7=CDlgHuaYuan
Resource4=IDD_HuaYuan

[CLS:CExerciseApp]
Type=0
HeaderFile=Exercise.h
ImplementationFile=Exercise.cpp
Filter=N
LastObject=CExerciseApp

[CLS:CExerciseDoc]
Type=0
HeaderFile=ExerciseDoc.h
ImplementationFile=ExerciseDoc.cpp
Filter=N

[CLS:CExerciseView]
Type=0
HeaderFile=ExerciseView.h
ImplementationFile=ExerciseView.cpp
Filter=C
LastObject=CExerciseView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_M_HuaYuan
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Exercise.cpp
ImplementationFile=Exercise.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_M_Start
Command18=ID_M_Stop
Command19=ID_M_Cls
Command20=ID_M_Open_JiSuanQi
Command21=ID_M_HuaYuan
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_JiSuan]
Type=1
Class=CDlgJiSuanQi
ControlCount=14
Control1=IDC_TEXT1,static,1342308865
Control2=IDC_a,edit,1350631553
Control3=IDC_TEXT2,static,1342308865
Control4=IDC_b,edit,1350631553
Control5=IDC_SUM,edit,1350641793
Control6=IDC_Cha,edit,1350641793
Control7=IDC_Ji,edit,1350641793
Control8=IDC_Chu,edit,1350641793
Control9=IDC_Yu,edit,1350641793
Control10=IDC_QiuHe,button,1342246656
Control11=IDC_QiuCha,button,1342246656
Control12=IDC_QiuJi,button,1342246656
Control13=IDC_QiuChu,button,1342246656
Control14=IDC_QiuYu,button,1342246656

[CLS:CDlgJiSuanQi]
Type=0
HeaderFile=DlgJiSuanQi.h
ImplementationFile=DlgJiSuanQi.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgJiSuanQi
VirtualFilter=dWC

[DLG:IDD_HuaYuan]
Type=1
Class=CDlgHuaYuan
ControlCount=8
Control1=IDC_HuaYuan_text1,static,1342308865
Control2=IDC_HuaYuan_x,edit,1350631553
Control3=IDC_HuaYuan_text2,static,1342308865
Control4=IDC_HuaYuan_text3,static,1342308865
Control5=IDC_HuaYuan_y,edit,1350631553
Control6=IDC_HuaYuan_r,edit,1350631553
Control7=IDC_HuaYuan_Draw,button,1342246656
Control8=IDC_HuaYua_Cencel,button,1342246656

[CLS:CDlgHuaYuan]
Type=0
HeaderFile=DlgHuaYuan.h
ImplementationFile=DlgHuaYuan.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_HuaYuan_r
VirtualFilter=dWC

