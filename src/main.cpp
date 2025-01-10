#include "Application.h"
int main()
{
	OpenGL context(800, 800, "Volumetric Thermal Expansion OpenGL Version");
	Application app(context);
	app.run();

	return 0;
}