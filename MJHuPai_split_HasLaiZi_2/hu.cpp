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

/*
@return:
true: ����true������Ҫ���ӾͿ��Թ���˳�ӻ��߿��ӡ�
false: ����false������Ҫ���ӣ���Ҫ������������iNeedLaiZiNum��
*/
bool bTongHuaSeCanBePu(int iCardsNum[MAX_CARD_ARRAY_SIZE], int iStartIndex, int iEndIndex, int & iNeedLaiZiNum)
{
	bool bNeedLaiZi = false;
	iNeedLaiZiNum = 0;

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
				bNeedLaiZi = true;
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
			else if(i + 1 <= iEndIndex && i + 2 <= iEndIndex && iCardsNum[i + 1] > 0 && iCardsNum[i + 2] > 0)
			{
				iCardsNum[i]--;
				iCardsNum[i + 1]--;
				iCardsNum[i + 2]--;
			}
			else
			{
				bNeedLaiZi = true;
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
				bNeedLaiZi = true;
			}
		}
		else
		{
			//������
		}
	}
	if (!bNeedLaiZi)
	{
		return true;
	}

	for (int i = iStartIndex; i <= iEndIndex; i++)
	{
		int iNum = iCardsNum[i];
		if (iNum == 1)
		{
			if ((i + 1 <= iEndIndex && iCardsNum[i + 1] == 0 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 0) ||
				(i + 1 == iEndIndex && iCardsNum[i + 1] == 0) ||
				(i == iEndIndex)
				)
			{
				iNeedLaiZiNum += 2;
			}
			else if ((i + 1 <= iEndIndex && iCardsNum[i + 1] == 1 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 0) ||
				(i + 1 <= iEndIndex && iCardsNum[i + 1] == 0 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 1) ||
				(i + 1 == iEndIndex && iCardsNum[i + 1] == 1)
				)
			{
				iNeedLaiZiNum += 1;
				if (i + 1 <= iEndIndex && iCardsNum[i + 1] > 0) iCardsNum[i + 1] = 0;
				if (i + 2 <= iEndIndex && iCardsNum[i + 2] > 0) iCardsNum[i + 2] = 0;
			}
			else if ((i + 1 <= iEndIndex && iCardsNum[i + 1] == 2 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 0) ||
				(i + 1 <= iEndIndex && iCardsNum[i + 1] == 0 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 2) ||
				(i + 1 == iEndIndex && iCardsNum[i + 1] == 2)
				)
			{
				iNeedLaiZiNum += 3;
				if (i + 1 <= iEndIndex && iCardsNum[i + 1] > 0) iCardsNum[i + 1] = 0;
				if (i + 2 <= iEndIndex && iCardsNum[i + 2] > 0) iCardsNum[i + 2] = 0;
			}
		}
		else if (iNum == 2)
		{
			if ((i + 1 <= iEndIndex && iCardsNum[i + 1] == 0 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 0) ||
				(i + 1 == iEndIndex && iCardsNum[i + 1] == 0) ||
				(i == iEndIndex)
				)
			{
				iNeedLaiZiNum += 1;
			}
            else if ((i + 1 <= iEndIndex && iCardsNum[i + 1] == 1 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 0) ||
                (i + 1 <= iEndIndex && iCardsNum[i + 1] == 0 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 1) ||
                (i + 1 == iEndIndex && iCardsNum[i + 1] == 1)
                )
            {
                iNeedLaiZiNum += 3;
                if (i + 1 <= iEndIndex && iCardsNum[i + 1] > 0) iCardsNum[i + 1] = 0;
                if (i + 2 <= iEndIndex && iCardsNum[i + 2] > 0) iCardsNum[i + 2] = 0;
            }
            else if ((i + 1 <= iEndIndex && iCardsNum[i + 1] == 2 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 0) ||
                (i + 1 <= iEndIndex && iCardsNum[i + 1] == 0 && i + 2 <= iEndIndex && iCardsNum[i + 2] == 2) ||
                (i + 1 == iEndIndex && iCardsNum[i + 1] == 2)
                )
            {
                iNeedLaiZiNum += 2;
                if (i + 1 <= iEndIndex && iCardsNum[i + 1] > 0) iCardsNum[i + 1] = 0;
                if (i + 2 <= iEndIndex && iCardsNum[i + 2] > 0) iCardsNum[i + 2] = 0;
            }
		}
		else
		{
			//������
		}
	}

	return false;
}

/*
@brief: �ܷ񹹳ɿ��ӡ�
*/
bool bTongHuaSeCanBeKeZi(int iCardsNum[MAX_CARD_ARRAY_SIZE], int iStartIndex, int iEndIndex, int & iNeedLaiZiNum)
{
    iNeedLaiZiNum = 0;

    for (int i = iStartIndex; i < iEndIndex; i++)
    {
        int iNum = iCardsNum[i];
        if (iNum == 1)
        {
            iNeedLaiZiNum += 2;
        }
        else if (iNum == 2)
        {
            iNeedLaiZiNum += 1;
        }
        else if (iNum == 4)
        {
            iNeedLaiZiNum += 2;
        }
    }

    return iNeedLaiZiNum > 0 ? false : true;
}

int iCalcLaiZiNum(int iCardsNum[MAX_CARD_ARRAY_SIZE], Card ucLaiZi)
{
	int iNum = iCardsNum[ucLaiZi];
	iCardsNum[ucLaiZi] = 0;
	return iNum;
}

bool bCanBePu(int iCardsNum[MAX_CARD_ARRAY_SIZE], Card ucLaiZi)
{
	/*�������ӵ�������ͬʱ�Ȱ������Ƴ���*/
	int iLaiZiNum = iCalcLaiZiNum(iCardsNum, ucLaiZi);

	//�ж������ܲ��ܹ���˳�ӻ��߿���
	int iNeedLaiZiNum = 0;
	if (!bTongHuaSeCanBePu(iCardsNum, CardYiWan, CardJiuWan, iNeedLaiZiNum))
	{
		if (iNeedLaiZiNum > iLaiZiNum)
		{
			return false;
		}
		else
		{
			iLaiZiNum -= iNeedLaiZiNum;
		}
	}
		
	//�ж������ܲ��ܹ���˳�ӻ��߿���
	iNeedLaiZiNum = 0;
	if (!bTongHuaSeCanBePu(iCardsNum, CardYaoJi, CardJiuTiao, iNeedLaiZiNum))
	{
		if (iNeedLaiZiNum > iLaiZiNum)
		{
			return false;
		}
		else
		{
			iLaiZiNum -= iNeedLaiZiNum;
		}
	}

	//�ж�Ͳ���ܲ��ܹ���˳�ӻ��߿���
	if (!bTongHuaSeCanBePu(iCardsNum, CardYiTong, CardJiuTong, iNeedLaiZiNum))
	{
		if (iNeedLaiZiNum > iLaiZiNum)
		{
			return false;
		}
		else
		{
			iLaiZiNum -= iNeedLaiZiNum;
		}
	}

	//�жϷ����ܲ��ܹ��ɿ���
	if (!bTongHuaSeCanBeKeZi(iCardsNum, CardDONG, CardBEI, iNeedLaiZiNum))
	{
		if (iNeedLaiZiNum > iLaiZiNum)
		{
			return false;
		}
		else
		{
			iLaiZiNum -= iNeedLaiZiNum;
		}
	}

	//�жϼ����ܲ��ܹ��ɿ���
	if (!bTongHuaSeCanBeKeZi(iCardsNum, CardZHONG, CardBAI, iNeedLaiZiNum))
	{
		if (iNeedLaiZiNum > iLaiZiNum)
		{
			return false;
		}
		else
		{
			iLaiZiNum -= iNeedLaiZiNum;
		}
	}

	return true;
}

bool bHu(Card aucHandCards[MAX_HANDCARD_NUM], Card ucLaiZi)
{
	/*�����ÿ���Ƶ�������iCardsNum���±����ÿ���ƣ�value���������Ƶ�������*/
	int iCardsNum[MAX_CARD_ARRAY_SIZE] = { 0 };
	vCalcCardsNum(aucHandCards, iCardsNum);

	/*�ҳ������������ơ������Ĭ������Ҳ���������ơ�*/
	Card aucJiang[MAX_HANDCARD_NUM] = { 0 };
	int iJiangNum = 0;
	vGetJiang(iCardsNum, aucJiang, iJiangNum);

	/*�������н��Ƶ������*/
	for (int i = 0; i < iJiangNum; i++)
	{
		Card ucJiang = aucJiang[i];
		int iCardsNumNoJiang[MAX_CARD_ARRAY_SIZE] = { 0 };
		memcpy(iCardsNumNoJiang, iCardsNum, MAX_CARD_ARRAY_SIZE * sizeof(int));
		iCardsNumNoJiang[ucJiang] -= 2;

		/*�жϿ۳��˽���֮��ʣ������ܲ��ܹ���˳��(1��2��3��)���߿���(1��1��1��)��*/
		if (bCanBePu(iCardsNumNoJiang, ucLaiZi))
		{
			return true;
		}
	}

	return false;
}
