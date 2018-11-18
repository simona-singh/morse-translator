
#define ledPin 5
#define potentiometer A0
#define audPin A2
#define DEBUG 0

char morse_a[] = ".-";
char morse_b[] = "-...";
char morse_c[] = "-.-.";
char morse_d[] = "-..";
char morse_e[] = ".";
char morse_f[] = "..-.";
char morse_g[] = "--.";
char morse_h[] = "....";
char morse_i[] = "..";
char morse_j[] = ".---";
char morse_k[] = "-.-";
char morse_l[] = ".-..";
char morse_m[] = "--";
char morse_n[] = "-.";
char morse_o[] = "---";
char morse_p[] = ".--.";
char morse_q[] = "--.-";
char morse_r[] = ".-.";
char morse_s[] = "...";
char morse_t[] = "-";
char morse_u[] = "..-";
char morse_v[] = "...-";
char morse_w[] = ".--";
char morse_x[] = "-..-";
char morse_y[] = "-.--";
char morse_z[] = "--..";
char morse_space[] = " ";
char morse_error[] = "........";

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(audPin, OUTPUT);
  pinMode(potentiometer, INPUT);

  String message;
  bool isText;
  String translation;

  message = promptReadIn("Enter message: ");
  Serial.println(message);
  isText = checkMessageType(message[0]);

  if (isText) {
    Serial.println("Translating text to Morse...");
    translation = ascii2morse(message);
    Serial.println("Translation: " + translation);
    sendDigital(ledPin, translation);
    //sendAnalog(audPin, translation);
  } else {
    Serial.println("Translating Morse to text...");
    translation = morse2ascii(message);
    Serial.println("Translation: " + translation);
  }
}

bool checkMessageType(char m){
  if (m == '.' || m == '-') {
    return false;
  } else {
    return true;
  }
}

String promptReadIn(String s) {
  Serial.print(s);
  while (!Serial.available()) {};
  return Serial.readString();
}

String morse2ascii(String m) {
  String translation;
  String toTranslate;
  int lengthOfString = m.length();
  for (int i = 0; i < lengthOfString; i++){
    if (m[i] == '/' || m[i] == ' ') {
      translation += morse2char(toTranslate);
      if (m[i] == ' ') {
        translation += ' ';
      }
      toTranslate = "";
    } else {
      toTranslate += m[i];
    }
  }
  translation += morse2char(toTranslate);
  return translation;
}

char morse2char(String m) {
  if (m == ".-") {
    return 'a';
  } else if (m == "-...") {
    return 'b';
  } else if (m == "-.-.") {
    return 'c';
  } else if (m == "-..") {
    return 'd';
  } else if (m == "."){
    return 'e';
  } else if (m == "..-.") {
    return 'f';
  } else if (m == "--.") {
    return 'g';
  } else if (m == "....") {
    return 'h';
  } else if (m == "..") {
    return 'i';
  } else if (m == ".---") {
    return 'j';
  } else if (m == "-.-") {
    return 'k';
  } else if (m == ".-..") {
    return 'l';
  } else if (m == "--") {
    return 'm';
  } else if (m == "-.") {
    return 'n';
  } else if (m == "---") {
    return 'o';
  } else if (m == ".--.") {
    return 'p';
  } else if (m == "--.-") {
    return 'q';
  } else if (m == ".-.") {
    return 'r';
  } else if (m == "...") {
    return 's';
  } else if (m == "-") {
    return 't';
  } else if (m == "..-") {
    return 'u';
  } else if (m == "...-") {
    return 'v';
  } else if (m == ".--") {
    return 'w';
  } else if (m == "-..-") {
    return 'x';
  } else if (m == "-.--") {
    return 'y';
  } else if (m == "--..") {
    return 'z';
  } else if (m == " ") {
    return ' ';
  } else {
    return '?';
  }
  
}

int getPotVal(){
  int potVal = analogRead(potentiometer);
  if (potVal < 250) {
    return 500;
  } else if (potVal < 750) {
    return 1000;
  } else {
    return 1500;
  }
}

void sendAnalog (int pin, String message) {
  int dot1 = 500;
  int freq = 440;
  int dotLength = getPotVal();

  for (int i = 0; i < message.length(); i++) {

    switch(message[i]){
      case '.':
        tone(pin, freq);
        delay(dotLength);
        noTone(pin);
        delay(dotLength);
        break;
      case '-':
        tone(pin, freq);
        delay(dotLength * 3);
        noTone(pin);
        delay(dotLength);
        break;
      case ' ':
        delay(dotLength * 3);
        break;
      case '/':
        delay(dotLength * 7);
        break;
    }
  }
}

void sendDigital(int p, String message){

  int dotLength = getPotVal();

  #if DEBUG == 1
  Serial.println(potVal);
  Serial.println(dotLength);
  #endif
  
  for (int i = 0; i < message.length(); i++) {

    switch(message[i]){
      case '.':
        digitalWrite(p, HIGH);
        delay(dotLength);
        digitalWrite(p, LOW);
        delay(dotLength);
        break;
      case '-':
        digitalWrite(p, HIGH);
        delay(dotLength * 3);
        digitalWrite(p, LOW);
        delay(dotLength);
        break;
      case ' ':
        delay(dotLength * 3);
        break;
      case '/':
        delay(dotLength * 7);
        break;
    }
  }
  
}

String ascii2morse (String s) {
  String translation;
  int lengthOfString = s.length();
  for (int i = 0; i < lengthOfString; i++){
    translation += char2morse(s[i]);
    if (i < (lengthOfString - 1)) { // checks if end of string
      translation += "/";
    }
  }
  return translation;
}

char * char2morse(char c) {
  switch(tolower(c)){
    case 'a':
      return morse_a;
      break;
    case 'b':
      return morse_b;
      break;
    case 'c':
      return morse_c;
      break;
    case 'd':
      return morse_d;
      break;
    case 'e':
      return morse_e;
      break;
    case 'f':
      return morse_f;
      break;
    case 'g':
      return morse_g;
      break;
    case 'h':
      return morse_h;
      break;
    case 'i':
      return morse_i;
      break;
    case 'j':
      return morse_j;
      break;
    case 'k':
      return morse_k;
      break;
    case 'l':
      return morse_l;
      break;
    case 'm':
      return morse_m;
      break;
    case 'n':
      return morse_n;
      break;
    case 'o':
      return morse_o;
      break;
    case 'p':
      return morse_p;
      break;
    case 'q':
      return morse_q;
      break;
    case 'r':
      return morse_r;
      break;
    case 's':
      return morse_s;
      break;
    case 't':
      return morse_t;
      break;
    case 'u':
      return morse_u;
      break;
    case 'v':
      return morse_v;
      break;
    case 'w':
      return morse_w;
      break;
    case 'x':
      return morse_x;
      break;
    case 'y':
      return morse_y;
      break;
    case 'z':
      return morse_z;
      break;
    case ' ':
      return morse_space;
      break;
    default:
      return morse_error;
      break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
