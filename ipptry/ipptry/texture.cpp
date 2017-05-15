#include "texture.h"

Texture::Texture()
{
	m_nTextureCount = 10;
}
Texture::~Texture()
{

}
bool Texture::AddGLTexture(unsigned short* pixeldata,int width, int height)
{
	//pixeldata = new unsigned short[width * height];
	//memset(pixeldata, 50, width * height); //a test demo zwj 20170510
	if (pixeldata == NULL)
	{
		return false;
	}

	// enlarge texture
	if (m_nTextureLoaded == m_nTextureCount)
	{
		m_nTextureCount += m_nTextureInc;
		CTexture* pNew = new CTexture[m_nTextureCount];
		memcpy(pNew, m_pTextures, sizeof(CTexture)*(m_nTextureCount - m_nTextureInc));
		delete[]m_pTextures;
		m_pTextures = pNew;
	}
	if (m_nTextureLoaded == 0)
	{
		CTexture* pNew = new CTexture[m_nTextureCount];
		m_pTextures = pNew;
	}

	//gen  a 2D textureImage for grayscale image
	GLuint texID;
	glGenTextures(1, &texID);
	// Copy file to OpenGL  
	//glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texID);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER); // what's the behavior if texture exceed width
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER); // what's the behavior if texture exceed height
	// Black/white checkerboard
	/*float pixels[] = {
		0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f
	};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);*/
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, pixeldata);
	m_pTextures[0].nIndex = texID; //save this texture 
	m_nTextureLoaded++;
	//glBindTexture(GL_TEXTURE_2D,0);
	return true;
}

void Texture::Bind(unsigned int unit)
{
	if (m_nTextureLoaded != 0)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D,m_pTextures[unit].nIndex);
		
	}
}