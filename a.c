#include <unistd.h>
int main()
{
	char	c1;
	char	c2;
	char	*s = "ğ";
	// c1 = *s;
	// s++;
	// c2 = *s;
	// write(1, &c1, 1);
	// write(1, &c2, 1);
    write(1, s, 2);
}