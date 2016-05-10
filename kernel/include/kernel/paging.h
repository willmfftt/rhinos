#ifndef _PAGING_H
#define _PAGING_H 1

extern void _load_page_directory(unsigned int *);
extern void _enable_paging();
void paging_install();

#endif /* _PAGING_H */
