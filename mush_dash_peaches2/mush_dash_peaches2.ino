#include <CapacitiveSensor.h>
#include <Keyboard.h>

// LED移位寄存器引脚
int latchPin = A1; //锁存引脚
int clockPin = A0; //时钟引脚
int dataPin = 12; //数据引脚


CapacitiveSensor   cs_d = CapacitiveSensor(8, 9);
CapacitiveSensor   cs_f = CapacitiveSensor(6, 7);

CapacitiveSensor   cs_j = CapacitiveSensor(4, 5);
CapacitiveSensor   cs_k = CapacitiveSensor(10, 11);

bool f_push = false;
bool j_push = false;
bool d_push = false;
bool k_push = false;

// 按键按下电容阈值 （大于此值时）
long press_val = 800;
// 按键释放电容阈值（小于此值时）
long release_val = 600;
// 电容值判断超时时间（单位：毫秒）
long time_out = 20;
// 电容值采样率（越大电容值越准确）
byte cp_resolution = 50;

// 取消注释进入调试模式
//#define DEBUG

void setup()
{
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  cs_d.set_CS_Timeout_Millis(time_out);
  cs_f.set_CS_Timeout_Millis(time_out);
  cs_j.set_CS_Timeout_Millis(time_out);
  cs_k.set_CS_Timeout_Millis(time_out);
  setLEDs(0);
  Keyboard.begin();
}

void loop()
{
#ifdef DEBUG
  long start = millis();
#endif
  long cp1 =  cs_f.capacitiveSensor(cp_resolution);
  if (cp1 == -2) {
    cp1 = 1200;
  }
  if (cp1 > press_val && !f_push) {
    Keyboard.press('f');
    f_push = true;
  } else if (cp1 < release_val && f_push) {
    Keyboard.release('f');
    f_push = false;
  }

  long cp2 =  cs_j.capacitiveSensor(cp_resolution);
  if (cp2 == -2) {
    cp2 = 1200;
  }
  if (cp2 > press_val && !j_push) {
    Keyboard.press('j');
    j_push = true;
  } else if (cp2 < release_val && j_push) {
    Keyboard.release('j');
    j_push = false;
  }

  long cp3 =  cs_d.capacitiveSensor(cp_resolution);
  if (cp3 == -2) {
    cp3 = 1200;
  }
  if (cp3 > press_val && !d_push) {
    Keyboard.press('d');
    d_push = true;
  } else if (cp3 < release_val && d_push) {
    Keyboard.release('d');
    d_push = false;
  }

  long cp4 =  cs_k.capacitiveSensor(cp_resolution);
  if (cp4 == -2) {
    cp4 = 1200;
  }
  if (cp4 > press_val && !k_push) {
    Keyboard.press('k');
    k_push = true;
  } else if (cp4 < release_val && k_push) {
    Keyboard.release('k');
    k_push = false;
  }

  boolean LEDs[] = {0, 0, 0, 0, 0, 0, 0, 0};
  if (d_push) {
    LEDs[7] = true;
    LEDs[6] = true;
  }
  if (f_push) {
    LEDs[5] = true;
    LEDs[4] = true;
  }
  if (j_push) {
    LEDs[3] = true;
    LEDs[2] = true;
  }
  if (k_push) {
    LEDs[1] = true;
    LEDs[0] = true;
  }
  setLEDs(LEDs);

#ifdef DEBUG
  Serial.print(millis() - start);
  Serial.print("ms");
  Serial.print("\t");
  Serial.print(cp1);
  Serial.print("\t");
  Serial.print(cp2);
  Serial.print("\t");
  Serial.print(cp3);
  Serial.print("\t");
  Serial.print(cp4);
  Serial.print("\t");
  for (int x = 0; x < 8; x++) {
    Serial.print(LEDs[x]);
  }
  Serial.println();
  delay(10);
#endif

}

void setLEDs(boolean data[]) {
  digitalWrite(latchPin, LOW);

  for (int x = 0; x < 8; x++) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, data[x]);
    digitalWrite(clockPin, HIGH);
  }

  digitalWrite(latchPin, HIGH);
}
