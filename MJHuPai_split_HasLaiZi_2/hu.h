#pragma once

#include "public.h"

#ifdef __cplusplus
extern "C" {
#endif

	/*
	@brief: �ж������ܲ��ܺ��ƣ�����3+3+3+3+2����ƣ���������(����)��
	@param aucHandCards[in]: 14�����ƣ�uint8_t���������顣
	@return bool: 
		true: ���Ժ��ơ�
		false: �����Ժ��ơ�
	*/
	bool bHu(Card aucHandCards[MAX_HANDCARD_NUM], Card ucLaiZi);


#ifdef __cplusplus
}
#endif

