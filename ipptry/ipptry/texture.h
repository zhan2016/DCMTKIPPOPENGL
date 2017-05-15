#ifndef TEXTURE_H
#define TEXTURE_H
//texture header file

//include the header file
#define GLEW_STATIC
#include <GL/glew.h> //opengl相关头文件
#include <GLFW/glfw3.h>
#include <fstream>

struct CTexture
{
	char pCharName[256];
	GLuint nIndex;

};

class Texture
{
public:
	Texture();

	void Bind(unsigned int unit);

	 ~Texture();

	//add a Texture
	bool AddGLTexture(unsigned short* pixeldata, int width, int height);
private:
	CTexture* m_pTextures; // texture array
	GLuint m_nTextureLoaded; //in used texture
	GLuint m_nTextureCount; //the specify number of texture
	GLuint m_nTextureInc; //Inc num when texture array is full

	/*read texture from file 
		or read texture from byte array
	*/

	bool LoadGLTextures(char* filename);


};

#endif