#ifndef STRUCT_H
#define STRUCT_H

#include"QVTKWidget.h"
#include"vtkSmartPointer.h"
#include"vtkRenderer.h"
#include"vtkImageActor.h"
#include<iostream>
#include<vector>

#include"Gridstruct.h"
using namespace std;
using namespace UMSM;

	typedef vector<int> intArray;//����int���vector����  
	typedef vector<double> realArray;//����double���vector����

	struct QVTKWidgetView
	{
		QVTKWidget* qvtkwidget;
		vtkSmartPointer< vtkRenderer> ren;
		QVTKWidgetView()
		{
			qvtkwidget = new QVTKWidget();
			ren = vtkSmartPointer< vtkRenderer>::New();
		};
	};

	typedef vector<point> PointArray;//��������vector����

	
	struct ContourGrid
	{
		int Row;
		int Col;
		point *Grids;
	};	
	struct CellRange
	{
		double minValue;
		double maxValue;
	};
	struct queryState{
		int LOD;
		bool isSpace;
		bool isProperty;
	};


#endif