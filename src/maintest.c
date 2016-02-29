#include <lem_in.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	t_map  map = parse_file(0);
	reprint_map(&map, NULL);
	write(1, "\n", 1);
	print_map(&map);
	put_weights(&map);
	print_map(&map);
}
