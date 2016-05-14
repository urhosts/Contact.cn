#include "Contact.h"

void menu()
{
	printf("***** 1.add     2.del    ****\n");
	printf("***** 3.modify  4.search ****\n");
	printf("***** 5.display 6.sort   ****\n");
	printf("***** 7.clear   0.exit   ****\n");
}

int main()
{
	Contact con;
	char input = 1;
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
			break;
		default:
			printf("Ñ¡Ôñ´íÎó\n");
			break;
		}
	}
	system("pause");
	return 0;
}