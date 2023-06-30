// << ---- Digital ピン番号常数設定
const int MotorR_A1 = 11; // 右モーター1番の後ろ //320 ~ 350 黒　// 30 白
const int MotorR_A2 = 10; // 右モーター2番の前
const int MotorL_B1 = 6; // 左モーター1番の後ろ
const int MotorL_B2 = 5; // 左モーター2番の前
// ----  >> Digital ピン番号常数設定終了

//センサー
int sen1 = A0; //左
int sen2 = A1; //右
int go   = 236; //基本速度 //236 127 137 大会時速度
int go2  = 127;  //右  カーブの際、反対タイヤは逆回転
int go3  = 137;  //左

//int val = 0; //センサー検査に使用した変数

// 初期化関数、Arduino実行時最初一回のみ実行
void setup() {
  // << ---- 左、右モーターを調整するデジタルピンの使用モードを出力に指定
  Serial.begin(9600);
  pinMode(MotorR_A1, OUTPUT);
  pinMode(MotorR_A2, OUTPUT);
  pinMode(MotorL_B1, OUTPUT);
  pinMode(MotorL_B2, OUTPUT);
  // ---- >> デジタルピン初期化終了

  // <<-- 左、右モーターをOFFに設定
  digitalWrite(MotorR_A1, LOW);
  digitalWrite(MotorR_A2, LOW);
  digitalWrite(MotorL_B1, LOW);
  digitalWrite(MotorL_B2, LOW);
  // <<-- 左、右モーターをOFFに設定終了
}

// 前進
void goStraight() {
  digitalWrite(MotorR_A1, LOW);
  digitalWrite(MotorR_A2, HIGH);
  digitalWrite(MotorL_B1, LOW);
  digitalWrite(MotorL_B2, HIGH);

  analogWrite(MotorR_A1, 0);
  analogWrite(MotorR_A2, go);
  analogWrite(MotorL_B1, 0);
  analogWrite(MotorL_B2, go);
  
  // duration期間の間は停止
//  delay(num);
}

// 後進
void goBack() {
  digitalWrite(MotorR_A1, HIGH);
  digitalWrite(MotorR_A2, LOW);
  digitalWrite(MotorL_B1, HIGH);
  digitalWrite(MotorL_B2, LOW);

  analogWrite(MotorR_A1, go);
  analogWrite(MotorR_A2, 0);
  analogWrite(MotorL_B1, go);
  analogWrite(MotorL_B2, 0);
  // duration期間の間は停止
//  delay(num);
}

// 右折
void turnRight() {
  digitalWrite(MotorR_A1, HIGH);
  digitalWrite(MotorR_A2, LOW);
  digitalWrite(MotorL_B1, LOW);
  digitalWrite(MotorL_B2, HIGH);

  analogWrite(MotorR_A1, go2);
  analogWrite(MotorR_A2, 0);
  analogWrite(MotorL_B1, 0);
  analogWrite(MotorL_B2, go);
  // duration期間の間は停止
//  delay(num);
}
// 左折
void turnLeft() {
  digitalWrite(MotorL_B1, LOW);
  digitalWrite(MotorL_B2, HIGH);
  digitalWrite(MotorR_A1, HIGH);
  digitalWrite(MotorR_A2, LOW);

  analogWrite(MotorR_A1, 0);
  analogWrite(MotorR_A2, go);
  analogWrite(MotorL_B1, go3);
  analogWrite(MotorL_B2, 0);
//  duration期間の間は停止
//  delay(num);
}

// Main関数、setup()関数実行後電源がOFFにならない限り連続的に実行
void loop() {
  //センサー確認時のコード
//  delay(50);
//  val = analogRead(sen1);
//  Serial.println(val);

 //センサー
  sen1 = analogRead(A0);
  sen2 = analogRead(A1);

  //実際の動きに関わるコード
  if(sen1 < 100 && sen2 < 100)      goStraight();
  else if(sen1 > 100 && sen2 < 100) turnLeft();
  else if(sen1 < 100 && sen2 > 100) turnRight();
  
//  else                              goBack();　//大会時には後進機能は要らなかった為コメントアウト
}
