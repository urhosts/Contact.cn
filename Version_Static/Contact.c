#include "Contact.h"

void _init_contact(Pcon pcon)
{
	memset(pcon->data, 0, MAX*sizeof(PeoInfo));
	pcon->size = 0;
}

void _add_contact(Pcon pcon)
{
	if (pcon->size >= MAX)
	{
		printf("�绰�����Ѵ���\n");
		return;
	}
	printf("���������֣�>");
	scanf("%s", pcon->data[pcon->size].name);
	printf("���������䣺>");
	scanf("%d", pcon->data[pcon->size].age);
	printf("�������Ա�>");
	scanf("%s", pcon->data[pcon->size].sex);
	printf("������绰��>");
	scanf("%s", pcon->data[pcon->size].tele);
	printf("�������ַ��>");
	scanf("%s", pcon->data[pcon->size].address);
	pcon->size++;
	printf("��ӳɹ�\n");
}

void _display_contact(Pcon pcon)
{
	int i = 0;
	printf("%9s\t%3s\t%4s\t%11s\t%10s\n", "name", "age", "sex", "tele", "address");
	for (i = 0; i <= pcon->size; i++)
	{
		printf("%9s\t%3s\t%4s\t%11s\t%10s\n",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].address);
	}
}

static int find_entry(Pcon pcon, char *name)
{
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		if (strcmp(pcon->data[i].name, name))
		{
			return i;
		}
	}
}

void _del_contact(Pcon pcon)
{
	int pos = 0;
	int index = 0;
	char name[NAME_MAX];
	if (pcon->size == 0)
	{
		printf("�绰��Ϊ��\n");
		return;
	}
	printf("Ҫɾ���˵�������>");
	scanf("%s", name);
	pos = find_entry(pcon, name);
	if (pos = -1)
	{
		printf("δ�ҵ�Ҫɾ������ϵ��\n");
		return;
	}
	for (index = pos; index < pcon->size; index++)
	{
		pcon->data[index] = pcon->data[index + 1];
	}
	pcon->size--;
	printf("ɾ���ɹ�\n");
}

void _search_contact(Pcon pcon)
{
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	printf("������Ҫ���ҵ��˵����֣�>");
	scanf("%s", name);
	pos = find_entry(pcon, name);
	if (pos == -1)
	{
		printf("ָ�����˲�����\n");
		return;
	}
	else
	{
		printf("%9s\t%3s\t%4s\t%11s\t%10s\n", "name", "age", "sex", "tele", "addr");
		printf("%9s\t%3d\t%4s\t%11s\t%10s\n",
			pcon->data[pos].name,
			pcon->data[pos].age,
			pcon->data[pos].sex,
			pcon->data[pos].tele,
			pcon->data[pos].address);
	}
}

void _modify_contact(Pcon pcon)
{
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	printf("������Ҫ�޸ĵ����֣�>");
	scanf("%s", name);
	pos = find_entry(pcon, name);
	if (pos == -1)
	{
		printf("ָ������ϵ�˲�����\n");
		return;
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", pcon->data[pos].name);
		printf("���������䣺>");
		scanf("%d", &(pcon->data[pos].age));
		printf("�������Ա�>");
		scanf("%s", pcon->data[pos].sex);
		printf("������绰��>");
		scanf("%s", pcon->data[pos].tele);
		printf("�������ַ��>");
		scanf("%s", pcon->data[pos].address);
	}
}

void _sort_contact(Pcon pcon)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pcon->size - 1; i++)
	{
		for (j = 0; j < pcon->size - 1 - i; j++)
		{
			if (strcmp(pcon->data[j].name, pcon->data[j + 1].name)>0)
			{
				PeoInfo tmp = { 0 };
				tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = tmp;
			}
		}
	}
}

void _clear_contact(Pcon pcon)
{
	pcon->size = 0;
}