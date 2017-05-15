#include "DrawManager.h"
#include <stdio.h>

void DrawManager::InitManager(int width, int height, char* title)
{
	Initgfw();
	createWnd(width, height, title);
	glfwMakeContextCurrent(window);
	InitGlew();

}

void DrawManager::createWnd(int width, int height, char* title)
{
	this->window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (this->window == nullptr)
	{
		printf("Failed to create GLFW window");
		glfwTerminate();
		return;
	}
}

void DrawManager::InitShader(char* vertexShader, char* FragmentShader)
{
	glShaderManager SM;
	this->Program = SM.loadfromFile("vertexshader.txt", "fragmentshader.txt"); //D:\\Ô´´úÂë\\OpenGLProject\\HelloTriangle\\HelloTriangle\\Debug\\

	if (this->Program == nullptr)
	{
		printf("Failed to create GLFW window");
		glfwTerminate();
		return;
	}
}

void DrawManager::InitVAO()
{
	
}

void DrawManager::InitVAOWithTexture(GLfloat vertices[], GLfloat textureCod[], int NumOfVerties)
{
	//GLuint VAO;
	glGenVertexArrays(1, &VAO);
	GLuint VBO,VBOTexure;
	glGenBuffers(1, &VBO);
	// 1. Bind Vertex Array Object
	glBindVertexArray(VAO);
	// 2. Copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices)* NumOfVerties, vertices, GL_STATIC_DRAW); //notice the second parameter must multipy the num of vertices!
	// 3. Then set our vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &VBOTexure);
	// 2. Copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBOTexure);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCod)* NumOfVerties, textureCod, GL_STATIC_DRAW);
	// 3. Then set our vertex attributes pointers
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	//4. Unbind the VAO
	glBindVertexArray(0);
}

GLuint* DrawManager::getProgram()
{
	return this->Program;
}

GLFWwindow* DrawManager::getWnd()
{
	return this->window;
}

GLuint DrawManager::getVAO()
{
	return this->VAO;
}

void DrawManager::Initgfw()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void DrawManager::InitGlew()
{
	glewExperimental = GL_TRUE; //Setting glewExperimental to true ensures GLEW uses more modern techniques for managing OpenGL functionality
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		system("pause");

	}
}

void DrawManager::bindProgram()
{
	glUseProgram(*Program);
}

void DrawManager::binVAO()
{
	glBindVertexArray(VAO);
}