#include "get_next_line.h"

int main()
{
	int fd;
	char *str;

	fd = open("test.txt", O_RDWR);
	//while(42)
	//{
		str = get_next_line(fd);
		printf("main ==> %s", str);
	//	if (str == NULL)
	//		break ;
		free(str);
	//}
	str = get_next_line(fd);
		printf("main second appel ==> %s", str);
	//	if (str == NULL)
	//		break ;
		free(str);
	//}
	close (fd);
	return (0);
}
