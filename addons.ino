//Start of my custom definitions
//
//pins on the first shift register
#define fuelWarn 1
#define fuelCaution 2
#define battDraw 3
#define battStat 4
#define battChar 5
#define sasStat 6
#define rcsStat 7
#define gearStat 8
#define lightStat 0

//setup shift register pins
//Pin connected to ST_CP of 74HC595
#define shiftLatchPin 8
//Pin connected to SH_CP of 74HC595
#define shiftClockPin 12
////Pin connected to DS of 74HC595
#define shiftDataPin 11

//remember the status of the shift register
int ledState;
//
//end of my custom definitions

//Start of custom functions
//
void shiftLED(int i, int newState) {
	int newLedState = ledState;
	switch(i) {
		case 1:	if (newState == 1){ newLedState = ledState + 1;  }else{ newLedState = ledState - 1;  } break;
		case 2: if (newState == 1){ newLedState = ledState + 2;	 }else{ newLedState = ledState - 2;  } break;
		case 3:	if (newState == 1){ newLedState = ledState + 4;	 }else{ newLedState = ledState - 4;  } break;
		case 4:	if (newState == 1){ newLedState = ledState + 8;  }else{ newLedState = ledState - 8;  } break; 
		case 5:	if (newState == 1){ newLedState = ledState + 16; }else{ newLedState = ledState - 16; } break;
		case 6:	if (newState == 1){ newLedState = ledState + 32; }else{	newLedState = ledState - 32; } break; 
		case 7:	if (newState == 1){ newLedState = ledState + 64; }else{ newLedState = ledState - 64; } break;
		case 8: if (newState == 1){ newLedState = ledState + 128;}else{	newLedState = ledState - 128;} break;         
	}
	ledState = newLedState;
	digitalWrite(shiftLatchPin, LOW);
	shiftOut(shiftDataPin, shiftClockPin, MSBFIRST, newLedState);
	digitalWrite(shiftLatchPin, HIGH);
}
//
//End of my custom functions
