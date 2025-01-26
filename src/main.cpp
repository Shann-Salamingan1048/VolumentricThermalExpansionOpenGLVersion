#include "Application.h"
int main()
{
	OpenGL context(1200, 1200, "Volumetric Thermal Expansion OpenGL Version");
	Application app(context);
	app.run();

	return 0;
}