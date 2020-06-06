
#include <iostream>
#include <GLFW/glfw3.h>

void close_now();
void close();
float radius = 0.5;
const float PI = 3.141529265;

int main_dev(void)
{
    if (!glfwInit()) {
        close_now();
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(500, 500, "Snakes Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        close_now();
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
        //set view
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        //Drawing
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++) {
            float rdn = i * PI / 180;
            glVertex2f(cos(rdn) * radius, sin(rdn) * radius);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    close();
}

void close_now() {
    exit(EXIT_FAILURE);
}
void close() {
    exit(EXIT_SUCCESS);
}