#include "../GUI/Application.h"

#include "../GUI/wxIncludes"

#include "../constants.h"

using namespace std;

void init(Application* app);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	Application* app(new Application());
	
	wxApp::SetInstance(app);
	wxEntryStart(argc, argv);
	wxTheApp->OnInit();

	init(app);

	wxTheApp->OnRun();
	wxTheApp->OnExit();
	wxEntryCleanup();

	return 0;
}
