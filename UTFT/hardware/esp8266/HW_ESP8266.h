#include <SPI.h>

// *** Hardwarespecific functions ***
void UTFT::_hw_special_init (  ) {
    if ( hwSPI ) {
        SPI.beginTransaction(SPISettings (16000000,MSBFIRST,SPI_MODE0));
    }
}

void UTFT::LCD_Writ_Bus ( char VH, char VL, byte mode ) {
    if ( hwSPI ) {
        if (mode == 1) {
            if ( VH == 1 ) {
                sbi ( P_RS, B_RS );
            } else {
                cbi ( P_RS, B_RS );
            }
            SPI.write ( VL );
        }
        else {
            uint8_t vh = VH, vl=VL;
            SPI.write16(vh | (vl << 8),false);
        }

        return;
    }

    switch ( mode ) {
    case 1:
        if ( display_serial_mode == SERIAL_4PIN ) {
            if ( VH == 1 )
                sbi ( P_SDA, B_SDA );
            else
                cbi ( P_SDA, B_SDA );
            pulse_low ( P_SCL, B_SCL );
        } else {
            if ( VH == 1 )
                sbi ( P_RS, B_RS );
            else
                cbi ( P_RS, B_RS );
        }

        if ( VL & 0x80 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x40 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x20 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x10 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x08 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x04 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x02 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x01 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        break;
    default:
        break;
    }
}

void UTFT::_set_direction_registers ( byte mode ) {
}

void UTFT::_fast_fill_16 ( int ch, int cl, long pix ) {

    uint16_t c16 = (uint16_t)ch | ((uint16_t)cl << 8);
    SPI.writePattern ((uint8_t *)&c16,sizeof(c16),pix);
}

void UTFT::_fast_fill_8 ( int ch, long pix ) {
}

void UTFT::_convert_float ( char *buf, double num, int width, byte prec ) {
}
