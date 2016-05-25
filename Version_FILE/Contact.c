#include "Contact.h"

void _init_contact(Pcon pcon)
{
	pcon->size = 0;
	pcon->capacity = INIT_CAPACITY;
	pcon->data = (PeoInfo*)malloc(pcon->capacity*sizeof(PeoInfo));
	if (pcon->data == NULL)
	{
		printf("out of memory\n");
		exit(EXIT_FAILURE);
	}
	memset(pcon->data, 0, pcon->capacity*sizeof(PeoInfo));
	_load_contact(pcon);
}

void _destory_contact(Pcon pcon)
{
	if (pcon->data != NULL)
	{
		free(pcon->data);
		pcon->data = NULL;
	}
}

void _check_capcity(Pcon pcon)
{
	if (pcon->size == pcon->capacity)
	{
		PeoInfo*tmp = realloc(pcon->data, (pcon->capacity + INC_CAPACITY)*sizeof(PeoInfo));
		if (tmp == NULL)
		{
			printf("out of memory\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			pcon->data = tmp;
		} 
		pcon->capacity += INC_CAPACITY;
	}
}

void _add_contact(Pcon pcon)
{
	/*if (pcon->size >= INIT_CAPACITY)
	{
	printf("�绰�����Ѵ���\n");
	return;
	}*/
	_check_capcity(pcon);
	printf("���������֣�>");
	scanf("%s", pcon->data[pcon->size].name);
	printf("���������䣺>");
	scanf("%d", &(pcon->data[pcon->size].age));
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
	for (i = 0; i < pcon->size; i++)
	{
		printf("%9s\t%3d\t%4s\t%11s\t%10s\n",
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
	if (pos == -1)
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
		printf("%9s\t%3\t%4s\t%11s\t%10s\n", "name", "age", "sex", "tele", "addr");
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

void _save_contact(Pcon pcon)
{
	int i = 0;
	FILE* pfWrite = fopen("contact.dat", "w");
	if (pfWrite == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < pcon->size; i++)
	{
		fwrite(&(pcon->data[i]), sizeof(PeoInfo),1, pfWrite);

	}
	fclose(pfWrite);
}

void _load_contact(Pcon pcon)
{
	PeoInfo tmp = { 0 };
	FILE *pfRead = fopen("contact.dat", "r");
	int i = 0;
	if (pfRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		_check_capcity(pcon);
		pcon->data[i] = tmp;
		i++;
		pcon->size++;
	}
}
