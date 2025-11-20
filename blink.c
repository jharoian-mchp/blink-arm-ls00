// Embedded Hello World
// Blink User LED0 which is attached to PC19

#include <pic32c.h>

void pc19_init();
void pc19_LED_toggle(void);

void systick_init(void);
uint32_t systick_not_expired(void);


int main() {
    pc19_init();
    systick_init();

    while(1) {
        pc19_LED_toggle();
        while(systick_not_expired());
    }
}

void pc19_init(void) {
    port_registers_t* port_regs = (port_registers_t *)PORT_REGS;
    port_regs->GROUP[2].PORT_OUTSET = PORT_OUTSET_OUTSET(PORT_PC19);
    port_regs->GROUP[2].PORT_DIRSET = PORT_DIRSET_DIRSET(PORT_PC19);
}

void pc19_LED_toggle(void) {
    port_registers_t* port_regs = (port_registers_t *)PORT_REGS;
    port_regs->GROUP[2].PORT_OUTTGL = PORT_OUTTGL_OUTTGL(PORT_PC19);
}

void systick_init(void) {
    // 1Hz ~ 5,000,000 or 0x4C4B40
    // 2Hz ~ 2,500,000 or 0x2625A0
    SysTick->LOAD = 0x2625A0;
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
}

uint32_t systick_not_expired(void) {
    return(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
}
