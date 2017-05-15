#ifndef Draw_Manager_H
#define Draw_Manager_H
#include "cwc.h"

class DrawManager
{
private:
	void Initgfw();
	void InitGlew();
	GLuint VAO;
	GLuint* Program;
	GLFWwindow* window;
public:
	void InitManager(int width, int height, char* title);
	void InitVAO();
	void InitVAOWithTexture(GLfloat vertices[], GLfloat textureCod[],int NumOfVerties);
	void createWnd(int width, int height, char* title);
	void InitShader(char* vertexShader, char* FragmentShader);
	void binVAO();
	GLuint getVAO();
	GLuint* getProgram();
	GLFWwindow* getWnd();
	void bindProgram();

};

#endif