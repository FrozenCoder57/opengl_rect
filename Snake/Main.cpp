#include <iostream>
#include <GLFW/glfw3.h>
//using namespace std;

int width = 500,
height = 500;
int blocksX = 20;
int blocksy = 20;
const double PI = 3.141592;
const float radius = 0.25;
GLFWwindow* window;


void drawRect(float x, float y, float width, float height);

void Draw() {
	//x, y, width, height
	drawRect(-0.2, -0.4, 0.4, 0.9);
}
void Update() {

}
void drawRect(float x, float y, float width, float height) {
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x, y + height);
	glVertex2f(x+ width, y + height);
	glEnd();
}
int main(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(width, height, "Snakes Game", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
		return 0;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	while (!glfwWindowShouldClose(window)) {
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	return 0;
}