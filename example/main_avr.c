// Entete

#define F_CPU 16000000
#include <avr/io.h>

// Les prototypes

void config_compteur0_generateurCTC(void);

int main(void) { 
	DDRB|=(1<<PB7);      // b7 du port B en sortie, OC0A
	config_compteur0_generateurCTC();
	while(1);
}

void config_compteur0_generateurCTC(void) {
	// Timer Counter Control Register 0 A
	// CTC  mode:                   b1:1  b0:0
	// OC0B disconnected b4:0 b5:0
	// OC0A  toggle on compare match b7:0 b6:1
	TCCR0A=(1<<COM0A0)|(1<<WGM01);

	// Timer Counter Control Register 0 B
	// Divisieur de frequence  (1024): b2:1 b1: 0 b0:1
	// Sortie OCA b7:0 et OCB: b6:0
	TCCR0B = 0b001;

	// Registre de données initialisé à 0
	TCNT0=0x00;

	// Registre de comparaison initialisé à 155
	OCR0A=155;
}
