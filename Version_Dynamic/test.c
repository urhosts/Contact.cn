#include "Contact.h"

void menu()
{
	printf("***** 1.add        2.del       ****\n");
	printf("***** 3.modify     4.search    ****\n");
	printf("***** 5.display    6.sort      ****\n");
	printf("***** 7.clear      0.save&exit ****\n");
}

void test()
{
	Contact con;
	int input = 1;
	_init_contact(&con);
	while (input)
	{
		menu();
		printf("ÇëÊäÈë£º>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			_add_contact(&con);
			break;
		case DEL:
			_del_contact(&con);
			break;
		case MODIFY:
			_modify_contact(&con);
			break;
		case SEARCH:
			_search_contact(&con);
			break;
		case DISPLAY:
			_display_contact(&con);
			break;
		case SORT:
			_sort_contact(&con);
			break;
		case CLEAR:
			_clear_contact(&con);
			break;
		case EXIT:
			_destory_contact(&con);
			break;
		default:
			printf("Ñ¡Ôñ´íÎó\n");
			break;
		}
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}