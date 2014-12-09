//Start of custom functions
//
int shiftLED(int ledState, int i, int newState) {
	int newLedState;
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
	digitalWrite(shiftLatchPin, LOW);
	shiftOut(shiftDataPin, shiftClockPin, MSBFIRST, newLedState);
	digitalWrite(shiftLatchPin, HIGH);
        return newLedState;
}
//
//End of my custom functions
void Indicators() {
  caution = 0;
  warning = 0;

  caution += VData.G > GCAUTION;
  warning += VData.G > GWARN;
  caution += VData.LiquidFuelS/VData.LiquidFuelTotS*100 < FUELCAUTION;
  warning += VData.LiquidFuelS/VData.LiquidFuelTotS*100 < FUELWARN;

  if (caution != 0)
    ledState = shiftLED(ledState, battChar, 1);
//    digitalWrite(YLED,HIGH);
  else
    ledState = shiftLED(ledState, sasStat, 1);
//    digitalWrite(YLED,LOW);

  if (warning != 0)
    digitalWrite(RLED,HIGH);
  else
    digitalWrite(RLED,LOW);
}

void initLEDS() {
//Custom LED's
//
	pinMode(shiftLatchPin, OUTPUT);
	pinMode(shiftClockPin, OUTPUT);
	pinMode(shiftDataPin, OUTPUT);
//
//End Custom LEDs

//pinMode(GLED,OUTPUT);
//  digitalWrite(GLED,HIGH);

//  pinMode(YLED,OUTPUT);
//  digitalWrite(YLED,HIGH);

//  pinMode(RLED,OUTPUT);
//  digitalWrite(RLED,HIGH);
}

void LEDSAllOff() {
//  digitalWrite(GLED,LOW);
//  digitalWrite(YLED,LOW);
// digitalWrite(RLED,LOW);
}


void InitTxPackets() {
  HPacket.id = 0;  
  CPacket.id = 101;
}








