#ifndef _PIT_H
#define _PIT_H 1

#define PIT_CLOCK_RATE 1193180
#define PIT_CHANNEL_0_DATA 0x40
#define PIT_CHANNEL_1_DATA 0x41
#define PIT_CHANNEL_2_DATA 0x42
#define PIT_COMMAND 0x43

void timer_phase(int hz);
void timer_handler();
void timer_wait(int ticks);
void timer_install();

#endif /* _PIT_H */
