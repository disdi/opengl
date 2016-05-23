#include <cmath>

#include <chrono>
#include <iostream>
#include <thread>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

static void ErrorCallback(int error, const char *description) {
  std::cerr << description << std::flush;
}

static void KeyCallback(GLFWwindow *window, int key, int scancode, int action,
                        int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }
}

int main(int argc, char **argv) {
  glfwSetErrorCallback(ErrorCallback);
  if (!glfwInit()) {
    return 1;
  }
  GLFWwindow *window =
      glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
  if (window == nullptr) {
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  glfwSetKeyCallback(window, KeyCallback);

  glewExperimental = GL_TRUE;
  glewInit();

  std::cout << "Renderer: " << glGetString(GL_RENDERER) << "\n";
  std::cout << "Version: " << glGetString(GL_VERSION) << "\n";

  while (!glfwWindowShouldClose(window)) {
    double time = glfwGetTime();
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    const GLfloat color[] = {(float)sin(time) * 0.5f + 0.5f,
                             (float)cos(time) * 0.5f + 0.5f, 0.0f, 1.0f};

    glClearBufferfv(GL_COLOR, 0, color);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
