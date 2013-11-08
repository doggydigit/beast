#include "GrapheGL.h"
 
// ======================================================================
GrapheGL::GrapheGL(wxWindow* parent, unsigned int fields, unsigned int objects)
:
wxGLCanvas(parent, wxID_ANY, wxPoint(2,-1), wxSize(400, 200), wxSUNKEN_BORDER|wxFULL_REPAINT_ON_RESIZE , wxT("")),
field(0)

{
	assert(fields>0 && objects>0);
	
	for (int i(0); i<objects; ++i) dataHist.push_back(std::vector<std::list<double> >(fields));
	for (int i(0); i<fields; ++i) scales.push_back(std::pair<double, double>(-100,100));
	
	colors.push_back(Color(255,0,0));
	colors.push_back(Color(0,255,0));
	colors.push_back(Color(0,0,255));
	
	Connect(wxEVT_IDLE, wxIdleEventHandler(GrapheGL::dessine));
}
GrapheGL::~GrapheGL()
{
}
void GrapheGL::setScale(double min, double max, int id)
{
	assert(dataHist[0].size()-1>=id);
	scales[id]=std::pair<double,double>(min,max);
}
void GrapheGL::addLine(double height, Color color)
{
	lines.push_back(std::pair<double, Color>(height, color));
}
void GrapheGL::dessine(wxIdleEvent& event)
{
	if (!GetContext()) return;
	SetCurrent();
	  
	glDisable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho (0, 400, 0, 200, 0, 1);
	glMatrixMode (GL_MODELVIEW);

	//Pour avoir de belles lignes lisses
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH); 
	
	//Fond blanc
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//Quadrillage
	glColor4d(0.0, 0.0, 0.0, 0.1);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	
	//Lignes verticales
	for (int i(20); i<=200; i+=20)
	{
		glVertex2i(0,i);
		glVertex2i(400,i);
	}
	
	//Lignes horizontales
	for (int i(20); i<=400; i+=20)
	{
		glVertex2i(i,0);
		glVertex2i(i,200);
	}
	glEnd();
	
	//Dessin des lignes
	for(int i(0); i<lines.size(); ++i)
	{
		lines[i].second.setGLColor();
		double height(scale(lines[i].first, field));
		glBegin(GL_LINES);
		glVertex2i(0,height);
		glVertex2i(400,height);
		glEnd();
	}

	drawData();
			
	glFlush();
	SwapBuffers();
}
void GrapheGL::clear()
{
	dataHist.clear();
	lines.clear();
}
double GrapheGL::scale(double data, unsigned int id)
{
	double min(scales[id].first);
	double max(scales[id].second);
	
	return 200/(max-min)*(data-min);
}
void GrapheGL::feed(double data, unsigned int field, unsigned int object)
{
	assert(dataHist[object].size()-1>=field);
	dataHist[object][field].push_back(scale(data, field));
	if (dataHist[object][field].size()>=400) dataHist[object][field].pop_front();
}
void GrapheGL::setField(unsigned int id)
{
	assert(dataHist[0].size()-1>=id);
	field=id;
}

void GrapheGL::drawData()
{
	glColor3ub(255,0,0);
	for (int i(0); i<dataHist.size(); ++i)
	{
		double x(0);
		if (i<colors.size()) colors[i].setGLColor();
		glBegin(GL_LINE_STRIP);
		for (std::list<double>::iterator it(dataHist[i][field].begin()); it!=dataHist[i][field].end(); ++it)
		{
			glVertex2d(x, *it); //on dessine les points de la courbe
			x+=1;
		}
		glEnd();
	}
}
