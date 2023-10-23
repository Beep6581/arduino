/*
   Arduino Uno.
   Displays a string character-by-character on an 8x8 LED matrix without using the driver shield.
   The code is meant to be verbose.
*/

const char message[] = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
const int charTime = 40;

// LED pins corresponding to Arduino pins
enum LedPins {
  LED_PIN_01 = 6,
  LED_PIN_02 = 8,
  LED_PIN_03 = A1,
  LED_PIN_04 = A2,
  LED_PIN_05 = 9,
  LED_PIN_06 = A4,
  LED_PIN_07 = 7,
  LED_PIN_08 = 4,
  LED_PIN_09 = 2,
  LED_PIN_10 = A3,
  LED_PIN_11 = A5,
  LED_PIN_12 = 5,
  LED_PIN_13 = A0,
  LED_PIN_14 = 3,
  LED_PIN_15 = 10,
  LED_PIN_16 = 11
};

// Rows counted from the top, columns from the left, 1-based.
// LED rows corresponding to Arduino pins
enum LedRows {
  LED_ROW_1 = LED_PIN_09,
  LED_ROW_2 = LED_PIN_14,
  LED_ROW_3 = LED_PIN_08,
  LED_ROW_4 = LED_PIN_12,
  LED_ROW_5 = LED_PIN_01,
  LED_ROW_6 = LED_PIN_07,
  LED_ROW_7 = LED_PIN_02,
  LED_ROW_8 = LED_PIN_05
};

enum LedCols {
  LED_COL_1 = LED_PIN_13,
  LED_COL_2 = LED_PIN_03,
  LED_COL_3 = LED_PIN_04,
  LED_COL_4 = LED_PIN_10,
  LED_COL_5 = LED_PIN_06,
  LED_COL_6 = LED_PIN_11,
  LED_COL_7 = LED_PIN_15,
  LED_COL_8 = LED_PIN_16
};

const int row[] = {LED_ROW_1, LED_ROW_2, LED_ROW_3, LED_ROW_4, LED_ROW_5, LED_ROW_6, LED_ROW_7, LED_ROW_8};
const int col[] = {LED_COL_1, LED_COL_2, LED_COL_3, LED_COL_4, LED_COL_5, LED_COL_6, LED_COL_7, LED_COL_8};

// String arrays use too much dynamic memory. PROGMEM allows to store data in flash (program) memory instead of SRAM.
const char chrA[8][9] PROGMEM = {
  "00111100",
  "01100110",
  "11000011",
  "11000011",
  "11111111",
  "11000011",
  "11000011",
  "11000011"
};

const char chrB[8][9] PROGMEM = {
  "11111100",
  "11000110",
  "11000110",
  "11111100",
  "11000110",
  "11000110",
  "11000110",
  "11111100"
};

const char chrC[8][9] PROGMEM = {
  "01111100",
  "11000110",
  "11000000",
  "11000000",
  "11000000",
  "11000000",
  "11000110",
  "01111100"
};

const char chrD[8][9] PROGMEM = {
  "11111100",
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "11111100"
};

const char chrE[8][9] PROGMEM = {
  "11111110",
  "11000000",
  "11000000",
  "11111100",
  "11000000",
  "11000000",
  "11000000",
  "11111110"
};

const char chrF[8][9] PROGMEM = {
  "11111110",
  "11000000",
  "11000000",
  "11111100",
  "11000000",
  "11000000",
  "11000000",
  "11000000"
};

const char chrG[8][9] PROGMEM = {
  "01111100",
  "11000110",
  "11000000",
  "11000000",
  "11001110",
  "11001110",
  "11000110",
  "01111100"
};

const char chrH[8][9] PROGMEM = {
  "11000110",
  "11000110",
  "11000110",
  "11111110",
  "11000110",
  "11000110",
  "11000110",
  "11000110"
};

const char chrI[8][9] PROGMEM = {
  "00111100",
  "00011000",
  "00011000",
  "00011000",
  "00011000",
  "00011000",
  "00011000",
  "00111100"
};

const char chrJ[8][9] PROGMEM = {
  "00001110",
  "00000110",
  "00000110",
  "00000110",
  "00000110",
  "00000110",
  "11000110",
  "01111100"
};

const char chrK[8][9] PROGMEM = {
  "11000110",
  "11001100",
  "11011000",
  "11110000",
  "11110000",
  "11011000",
  "11001100",
  "11000110"
};

const char chrL[8][9] PROGMEM = {
  "11000000",
  "11000000",
  "11000000",
  "11000000",
  "11000000",
  "11000000",
  "11000000",
  "11111110"
};

const char chrM[8][9] PROGMEM = {
  "11000110",
  "11101110",
  "11101110",
  "11010110",
  "11000110",
  "11000110",
  "11000110",
  "11000110"
};

const char chrN[8][9] PROGMEM = {
  "11000110",
  "11100110",
  "11110110",
  "11010110",
  "11001110",
  "11000110",
  "11000110",
  "11000110"
};

const char chrO[8][9] PROGMEM = {
  "00111100",
  "01100110",
  "11000011",
  "11000011",
  "11000011",
  "11000011",
  "01100110",
  "00111100"
};

const char chrP[8][9] PROGMEM = {
  "11111100",
  "11000110",
  "11000110",
  "11111100",
  "11000000",
  "11000000",
  "11000000",
  "11000000"
};

const char chrQ[8][9] PROGMEM = {
  "01111000",
  "11001100",
  "11000110",
  "11000110",
  "11000110",
  "11001100",
  "01111000",
  "00001110"
};

const char chrR[8][9] PROGMEM = {
  "11111100",
  "11000110",
  "11000110",
  "11111100",
  "11100000",
  "11011000",
  "11001100",
  "11000110"
};

const char chrS[8][9] PROGMEM = {
  "01111100",
  "11000110",
  "11000000",
  "01110000",
  "00001100",
  "00000110",
  "11000110",
  "01111100"
};

const char chrT[8][9] PROGMEM = {
  "11111111",
  "00011000",
  "00011000",
  "00011000",
  "00011000",
  "00011000",
  "00011000",
  "00011000"
};

const char chrU[8][9] PROGMEM = {
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "01111100"
};

const char chrV[8][9] PROGMEM = {
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "01111100",
  "00111000"
};

const char chrW[8][9] PROGMEM = {
  "11000110",
  "11000110",
  "11000110",
  "11000110",
  "11010110",
  "11101110",
  "11101110",
  "11000110"
};

const char chrX[8][9] PROGMEM = {
  "11000110",
  "11000110",
  "01111100",
  "00111000",
  "00111000",
  "01111100",
  "11000110",
  "11000110"
};

const char chrY[8][9] PROGMEM = {
  "11000110",
  "11000110",
  "11000110",
  "01111100",
  "00111000",
  "00111000",
  "00111000",
  "00111000"
};

const char chrZ[8][9] PROGMEM = {
  "11111110",
  "00000110",
  "00001100",
  "00011000",
  "00110000",
  "01100000",
  "11000000",
  "11111110"
};

const char chr0[8][9] PROGMEM = {
  "01111100",
  "11000110",
  "11001110",
  "11010110",
  "11100110",
  "11000110",
  "11000110",
  "01111100"
};

const char chr1[8][9] PROGMEM = {
  "00011000",
  "00111000",
  "01111000",
  "00011000",
  "00011000",
  "00011000",
  "00011000",
  "00111100"
};

const char chr2[8][9] PROGMEM = {
  "01111100",
  "11000110",
  "00000110",
  "00001100",
  "00011000",
  "00110000",
  "01100000",
  "11111110"
};

const char chr3[8][9] PROGMEM = {
  "01111100",
  "11000110",
  "00000110",
  "00001100",
  "00000110",
  "00000110",
  "11000110",
  "01111100"
};

const char chr4[8][9] PROGMEM = {
  "00001100",
  "00011100",
  "00111100",
  "01101100",
  "11001100",
  "11111110",
  "00001100",
  "00001100"
};

const char chr5[8][9] PROGMEM = {
  "11111110",
  "11000000",
  "11000000",
  "11111100",
  "00000110",
  "00000110",
  "11000110",
  "01111100"
};

const char chr6[8][9] PROGMEM = {
  "01111100",
  "11000110",
  "11000000",
  "11111100",
  "11000110",
  "11000110",
  "11000110",
  "01111100"
};

const char chr7[8][9] PROGMEM = {
  "11111110",
  "00000110",
  "00000110",
  "00001100",
  "00011000",
  "00110000",
  "00110000",
  "00110000"
};

const char chr8[8][9] PROGMEM = {
  "01111100",
  "11000110",
  "11000110",
  "01111100",
  "11000110",
  "11000110",
  "11000110",
  "01111100"
};

const char chr9[8][9] PROGMEM = {
  "01111100",
  "11000110",
  "11000110",
  "11000110",
  "01111110",
  "00000110",
  "00000110",
  "01111100"
};

void setup() {
  // For debugging. Initialize serial communication with a baud rate of 9600bps.
  Serial.begin(9600);

  for (int i = 0; i < 8; i++) {
    pinMode(row[i], OUTPUT);
    pinMode(col[i], OUTPUT);

    digitalWrite(row[i], LOW);
    digitalWrite(col[i], HIGH);
  }
}

void loop() {
  showString(message);
  showBlank();
}

void showString(const char* message) {
  for (int i = 0; i < strlen(message); i++) {
    char chr[8][9];
    char currentChar = message[i];

    if ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= '0' && currentChar <= '9')) {
      int charIndex = (currentChar >= 'A' && currentChar <= 'Z') ? currentChar - 'A' : currentChar - '0' + 26;
      switch (charIndex) {
        case 0: memcpy_P(chr, chrA, sizeof(chr)); break;
        case 1: memcpy_P(chr, chrB, sizeof(chr)); break;
        case 2: memcpy_P(chr, chrC, sizeof(chr)); break;
        case 3: memcpy_P(chr, chrD, sizeof(chr)); break;
        case 4: memcpy_P(chr, chrE, sizeof(chr)); break;
        case 5: memcpy_P(chr, chrF, sizeof(chr)); break;
        case 6: memcpy_P(chr, chrG, sizeof(chr)); break;
        case 7: memcpy_P(chr, chrH, sizeof(chr)); break;
        case 8: memcpy_P(chr, chrI, sizeof(chr)); break;
        case 9: memcpy_P(chr, chrJ, sizeof(chr)); break;
        case 10: memcpy_P(chr, chrK, sizeof(chr)); break;
        case 11: memcpy_P(chr, chrL, sizeof(chr)); break;
        case 12: memcpy_P(chr, chrM, sizeof(chr)); break;
        case 13: memcpy_P(chr, chrN, sizeof(chr)); break;
        case 14: memcpy_P(chr, chrO, sizeof(chr)); break;
        case 15: memcpy_P(chr, chrP, sizeof(chr)); break;
        case 16: memcpy_P(chr, chrQ, sizeof(chr)); break;
        case 17: memcpy_P(chr, chrR, sizeof(chr)); break;
        case 18: memcpy_P(chr, chrS, sizeof(chr)); break;
        case 19: memcpy_P(chr, chrT, sizeof(chr)); break;
        case 20: memcpy_P(chr, chrU, sizeof(chr)); break;
        case 21: memcpy_P(chr, chrV, sizeof(chr)); break;
        case 22: memcpy_P(chr, chrW, sizeof(chr)); break;
        case 23: memcpy_P(chr, chrX, sizeof(chr)); break;
        case 24: memcpy_P(chr, chrY, sizeof(chr)); break;
        case 25: memcpy_P(chr, chrZ, sizeof(chr)); break;
        case 26: memcpy_P(chr, chr0, sizeof(chr)); break;
        case 27: memcpy_P(chr, chr1, sizeof(chr)); break;
        case 28: memcpy_P(chr, chr2, sizeof(chr)); break;
        case 29: memcpy_P(chr, chr3, sizeof(chr)); break;
        case 30: memcpy_P(chr, chr4, sizeof(chr)); break;
        case 31: memcpy_P(chr, chr5, sizeof(chr)); break;
        case 32: memcpy_P(chr, chr6, sizeof(chr)); break;
        case 33: memcpy_P(chr, chr7, sizeof(chr)); break;
        case 34: memcpy_P(chr, chr8, sizeof(chr)); break;
        case 35: memcpy_P(chr, chr9, sizeof(chr)); break;
      }
      showCharByRow(chr);
    } else {
      showBlank();
    }
  }
}

void showCharByRow(const char symbol[8][9]) {
  for (int t = 0; t < charTime; t++) {
    for (int r = 0; r < 8; r++) {
      digitalWrite(row[r], HIGH);
      const char* strRow = symbol[r];
      for (int c = 0; c < 8; c++) {
        char ch = strRow[c];
        digitalWrite(col[c], ch == '0' ? HIGH : LOW);
      }
      delay(2);
      digitalWrite(row[r], LOW);
    }
  }
}

void showBlank() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(row[i], LOW);
    digitalWrite(col[i], HIGH);
  }
  delay(charTime * 20);
}
