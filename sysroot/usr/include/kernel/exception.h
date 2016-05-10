#ifndef _EXCEPTION_H
#define _EXCEPTION_H 1

void exc_divide_by_zero();
void exc_debug();
void exc_nmi();
void exc_brp();
void exc_overflow();
void exc_bound();
void exc_invopcode();
void exc_device_not_avail();
void exc_double_fault();
void exc_coproc();
void exc_invtss();
void exc_segment_not_present();
void exc_ssf();
void exc_gpf();
void exc_pf();
void exc_reserved();
void install_exceptions();

#endif /* _EXCEPTION_H */
