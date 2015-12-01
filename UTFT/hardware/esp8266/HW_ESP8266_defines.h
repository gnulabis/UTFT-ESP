// *** Hardwarespecific defines ***
#define cbi(reg, bitmask) GPOC = bitmask
#define sbi(reg, bitmask) GPOS = bitmask
#define pulse_high(reg, bitmask) sbi(reg, bitmask); cbi(reg, bitmask);
#define pulse_low(reg, bitmask) cbi(reg, bitmask); sbi(reg, bitmask);

#define cport(port, data) port &= data
#define sport(port, data) port |= data

#define swap(type, i, j) {type t = i; i = j; j = t;}

#define fontbyte(x) pgm_read_byte(&cfont.font[x])

#define regtype volatile uint32_t
#define regsize uint32_t
#define bitmapdatatype unsigned int*
