// ippImageprocess.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include "ipp.h" //����ͷ�ļ�


int _tmain(int argc, _TCHAR* argv[])
{
	Ipp64u start, end;

	start = ippGetCpuClocks(); //�õ�CPU��ʼʱ�ӣ�ע�⺯��ǰ׺
	end = ippGetCpuClocks(); //�õ�CPU��ֹʱ��

	//���
	printf("clocks to do nothing:%d \n", (Ipp32s)(end - start));
	//�����ӡhello world����µ�ʱ��
	start = ippGetCpuClocks();
	printf("Hello World\n");
	end = ippGetCpuClocks();
	printf("Clocks to printf 'hello world':%d\n", (Ipp32s)(end - start));
	return 0;
}

