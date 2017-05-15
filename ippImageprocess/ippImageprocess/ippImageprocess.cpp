// ippImageprocess.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include "ipp.h" //引入头文件


int _tmain(int argc, _TCHAR* argv[])
{
	Ipp64u start, end;

	start = ippGetCpuClocks(); //得到CPU开始时钟，注意函数前缀
	end = ippGetCpuClocks(); //得到CPU终止时钟

	//输出
	printf("clocks to do nothing:%d \n", (Ipp32s)(end - start));
	//输出打印hello world情况下的时差
	start = ippGetCpuClocks();
	printf("Hello World\n");
	end = ippGetCpuClocks();
	printf("Clocks to printf 'hello world':%d\n", (Ipp32s)(end - start));
	return 0;
}

