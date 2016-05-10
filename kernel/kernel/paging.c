#include <kernel/paging.h>

#include <stdint.h>

void paging_install()
{
	uint32_t page_directory[1024] __attribute__((aligned(4096)));
	uint32_t first_page_table[1024] __attribute__((aligned(4096)));
	
	unsigned int i;
	for (i = 0; i < 1024; i++) {
		page_directory[i] = 0x00000002;
		first_page_table[i] = (i * 0x1000) | 3;
	}

	page_directory[0] = ((unsigned int) first_page_table) | 3;

	_load_page_directory(page_directory);
	_enable_paging();
}
