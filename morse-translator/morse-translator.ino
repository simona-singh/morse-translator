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

void setup() {
  Serial.begin(9600);
  Serial.println(char2morse('s'));
  Serial.println(char2morse('o'));
  Serial.println(char2morse('E'));
  Serial.println(char2morse('T'));
  Serial.println(char2morse(' '));
  Serial.println(char2morse('&'));
  Serial.println(ascii2morse("sos"));
}

String ascii2morse (String s) {
  String translation;
  for (int i = 0; i < s.length(); i++){
    translation += "/";
    translation += char2morse(s[i]);
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
      return " ";
      break;
    default:
      return "........";
      break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
