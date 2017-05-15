#include <stdio.h>

#include "ipp.h " //引入ipp头文件
#include "DicomImageInfotj.h" //引入dicom操作头文件
#include "DrawManager.h"
#include "texture.h"


int main()

{
	OFCondition status;
	OFString somedata;
	char* filename = "C:\\Users\\cs\\Desktop\\ippcode\\ipptry\\Debug\\testdcm.985208";
	DicomImageInfotj* dicomimage = new DicomImageInfotj(filename); //resolve dicom image
	
	if (!dicomimage->InitImageInfo()) //now we get all image info
	{
		std::cout << "failed to get data info" << std::endl;
	}

	//constructor a vertext,the texture will fill this rectangle
	GLfloat vertices[] = {
		-1,-1,0,
		-1,1,0,
		1,1,0,
		-1,-1,0,
		1,-1,0,
		1,1,0
	};
	GLfloat textCoodinates[] = {
		0,0,
		0,1,
		1,1,
		0,0,
		1,0,
		1,1
	};
	int NumOfVerties = 18;

	//display pixel with opengl 

	//2 load shader creaate a windows
	DrawManager DM;
	DM.InitManager(1300, 1400, "2DImage");
	//3 load shader and init VAO
	DM.InitShader("vertexshader.txt", "fragmentshader.txt");
	//DM.bindProgram();
	DM.InitVAOWithTexture(vertices, textCoodinates, NumOfVerties);
	//DM.binVAO();
	//4 load texture
	Texture texture;
	texture.AddGLTexture((unsigned short*)dicomimage->imageinfo->bmppixelData, dicomimage->imageinfo->columns, dicomimage->imageinfo->rows);
	//glEnable(GL_TEXTURE_2D);

	//keep drawing until a stop signal explicity told
	while (!glfwWindowShouldClose(DM.getWnd()))
	{
		
		//texture.Bind(0);
		// Check and call events
		glfwPollEvents();
		// Rendering commands here
		//.....
		//glDrawPixels(dicomimage->imageinfo->columns, dicomimage->imageinfo->rows, GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT, dicomimage->imageinfo->bmppixelData);
		DM.binVAO();
		DM.bindProgram();
		texture.Bind(0);
		glUniform1i(glGetUniformLocation(*(DM.getProgram()), "ourTexture1"), 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
		// Swap the buffers
		glfwSwapBuffers(DM.getWnd());
	}
	return 0;

}



void testipp()
{
	Ipp64u start, end;

	start = ippGetCpuClocks(); // 得到CPU开始时钟，这里调用的是ipp函数，注意函数前缀 

	end = ippGetCpuClocks(); // 得到CPU终止时钟

	//输出什么都不做的时差

	printf("Clocks to do nothing: %d \n", (Ipp32s)(end - start));

	//输出打印Hello Word情况下的时差

	start = ippGetCpuClocks();

	printf("Hello World\n");

	end = ippGetCpuClocks();

	printf("Clocks to print 'hello world': %d \n", (Ipp32s)(end - start));
}