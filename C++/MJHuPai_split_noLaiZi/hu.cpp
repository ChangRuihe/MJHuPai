#include "hu.h"
#include <stdlib.h>
#include <string.h>


void vCalcCardsNum(Card aucHandCards[MAX_HANDCARD_NUM], int iCardsNum[MAX_CARD_ARRAY_SIZE])
{
	for (int i = 0; i < MAX_HANDCARD_NUM; i++)
	{
		iCardsNum[aucHandCards[i]]++;
	}
}

void vGetJiang(int iCardsNum[MAX_CARD_ARRAY_SIZE], Card aucJiang[MAX_HANDCARD_NUM], int & riJiangNum)
{
	memset(aucJiang, 0, MAX_HANDCARD_NUM);
	riJiangNum = 0;

	for (int i = 0; i < MAX_CARD_ARRAY_SIZE; i++)
	{
		if (iCardsNum[i] >= 2)
		{
			aucJiang[riJiangNum++] = i;
		}
	}
}

bool bTongHuaSeCanBePu(int iCardsNum[MAX_CARD_ARRAY_SIZE], int iStartIndex, int iEndIndex)
{
	for (int i = iStartIndex; i <= iEndIndex; i++)
	{
		int iNum = iCardsNum[i];
		if (iNum == 1)
		{
			if (i + 1 <= iEndIndex && i + 2 <= iEndIndex && iCardsNum[i + 1] > 0 && iCardsNum[i + 2] > 0)
			{
				iCardsNum[i]--;
				iCardsNum[i + 1]--;
				iCardsNum[i + 2]--;
			}
			else
			{
				return false;
			}
		}
		else if (iNum == 2)
		{
			if (i + 1 <= iEndIndex && i + 2 <= iEndIndex && iCardsNum[i + 1] > 1 && iCardsNum[i + 2] > 1)
			{
				iCardsNum[i] -= 2;;
				iCardsNum[i + 1] -= 2;
				iCardsNum[i + 2] -= 2;
			}
			else
			{
				return false;
			}
		}
		else if (iNum == 3)
		{
			iCardsNum[i] -= 3;
		}
		else if (iNum == 4)
		{
			iCardsNum[i] -= 3;
			if (i + 1 <= iEndIndex && i + 2 <= iEndIndex && iCardsNum[i + 1] > 0 && iCardsNum[i + 2] > 0)
			{
				iCardsNum[i]--;
				iCardsNum[i + 1]--;
				iCardsNum[i + 2]--;
			}
			else
			{
				return false;
			}
		}
		else
		{
			//������
		}
	}

	return true;
}

bool bCanBePu(int iCardsNum[MAX_CARD_ARRAY_SIZE])
{
	if (!bTongHuaSeCanBePu(iCardsNum, CardYiWan, CardJiuWan)) return false; //�ж������ܲ��ܹ���˳�ӻ��߿���
	if (!bTongHuaSeCanBePu(iCardsNum, CardYaoJi, CardJiuTiao)) return false; //�ж������ܲ��ܹ���˳�ӻ��߿���
	if (!bTongHuaSeCanBePu(iCardsNum, CardYiTong, CardJiuTong)) return false; //�ж�Ͳ���ܲ��ܹ���˳�ӻ��߿���
	if (!bTongHuaSeCanBePu(iCardsNum, CardDONG, CardBEI)) return false; //�жϷ����ܲ��ܹ���˳�ӻ��߿���
	if (!bTongHuaSeCanBePu(iCardsNum, CardZHONG, CardBAI)) return false; //�жϼ����ܲ��ܹ���˳�ӻ��߿���
	return true;
}

bool bHu(Card aucHandCards[MAX_HANDCARD_NUM])
{
	/*�����ÿ���Ƶ�������iCardsNum���±����ÿ���ƣ�value���������Ƶ�������*/
	int iCardsNum[MAX_CARD_ARRAY_SIZE] = { 0 };
	vCalcCardsNum(aucHandCards, iCardsNum);

	/*�ҳ������������ơ�*/
	Card aucJiang[MAX_HANDCARD_NUM] = { 0 };
	int iJiangNum = 0;
	vGetJiang(iCardsNum, aucJiang, iJiangNum);

	/*�������н��Ƶ������*/
	for (int i = 0; i < iJiangNum; i++)
	{
		Card ucJiang = aucJiang[i];
		int iCardsNumNoJiang[MAX_CARD_ARRAY_SIZE] = { 0 };
		memcpy(iCardsNumNoJiang, iCardsNum, MAX_CARD_ARRAY_SIZE);
		iCardsNumNoJiang[ucJiang] -= 2;

		/*�жϿ۳��˽���֮��ʣ������ܲ��ܹ���˳��(1��2��3��)���߿���(1��1��1��)��*/
		if (bCanBePu(iCardsNumNoJiang))
		{
			return true;
		}
	}

	return false;
}
