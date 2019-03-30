#ifndef MYWIDGET_H
#define MYWIDGET_H

#include "QtGui"
#include <QWidget>
#include "qlabel.h"
#include "qboxlayout.h"
#include "qpushbutton.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
	~MyWidget();
public:
	void setCentralWidget(int WidgetIndex, bool istrag, bool domodel, bool islayout);
	QWidget* CentralFrame;
	bool iscloseenable = true;
	bool isclose = true;
private:
	int vtheight = 20.0;  //��������߶�
    QLabel* LeftFrame;
    QLabel* RightFrame;
    QLabel* ButtonFrame;
    QLabel* TopFrame;	

	QPushButton* titleiconbT;
	QLabel* titlelB;

	QPushButton* minbT;
	QPushButton* maxbT;
	QPushButton* closebT;

	int mincloseval = 0;
	int titlelen = 50;

	QSize Centresize;
	
	void setSize();

	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void showEvent(QShowEvent *e) Q_DECL_OVERRIDE;
	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
	int setCursorStyle(const QPoint& curPoint);    // ��ǰλ�����������ʽ

	QPoint m_MousePressPos;				    // �����λ��  
	QPoint m_MouseMovePos;				    // ����ƶ�λ��  
	bool   m_bMousePressed = false;		   // ����Ƿ���  
	int    m_nMouseResize ;				   // ������ô�С  
	bool   m_bMouseResizePressed = false;    // ���ô�С�İ���  
	QPoint m_ResizePressPos;			   // ���ô�С��갴�µĵ�

	void resetgrid(QWidget* frm, double fx, double fy, int index);

	void calchildWidget(QWidget* w);

	int widgetindex;

	QVector<QWidget*> childwidget;
	QVector<QRect> childGeo;

	bool resizeInit=false;
	bool resizenable = false;

	void resizeEvent(QResizeEvent* e);
	int curwidth;
	int curheight;

	bool modal=false;
	bool layout = false;

	bool ismaxsize=false;
	int sizemode = 2; //1-- min 2--mid 3-max

	int hwidth = 1.0;     //���ұ߿���	
	int vbheight = 1.0;   //�ײ��߿�߶�

	QSize MidSize;
	QPoint frmpos;

	bool record_mid_size=true;

	bool isresizedmove = false;
	bool ismousemove=false;

protected :
	void paintEvent(QPaintEvent * event);
	void mouseDoubleClickEvent(QMouseEvent* e);
	bool eventFilter(QObject *object, QEvent *event);//�¼�������
private slots:
	void Widgetresize(double fx, double fy);
	void ScreenChange();
	void WidgetMinimun();
public slots:
	void Widgetclose();
	void setTitle(const QString Icon,QString str);
	void setTitle(QString str);
	void showmaxbT();
};
#endif // MYWIDGET_H
