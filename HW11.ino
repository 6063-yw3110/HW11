// 定义引脚
const int potPin = A0; // 电位器连接到A0
const int buttonPin = 2; // 按钮连接到D2
const int ledPinSuccess = 4; // 绿色LED连接到D4
const int ledPinFail = 5; // 红色LED连接到D5

// 变量初始化
int potValue = 0; // 存储电位器读数
int buttonState = 0; // 存储按钮状态

void setup() {
  // 初始化引脚模式
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPinSuccess, OUTPUT);
  pinMode(ledPinFail, OUTPUT);

  // 初始化串口通信
  Serial.begin(9600);
}

void loop() {
  // 读取电位器的值
  potValue = analogRead(potPin);
  // 读取按钮的状态
  buttonState = digitalRead(buttonPin);

  // 在串口监视器中打印电位器的模拟值
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  // 检查按钮是否被按下
  if (buttonState == LOW) {
    // 检查电位器是否在最右边的位置
    if (potValue > 2000) { // 例如，大于900视为最右边
      digitalWrite(ledPinSuccess, HIGH); // 点亮绿色LED
      digitalWrite(ledPinFail, LOW); // 关闭红色LED
    } else {
      digitalWrite(ledPinFail, HIGH); // 点亮红色LED
      digitalWrite(ledPinSuccess, LOW); // 关闭绿色LED
    }
    delay(1000); // 等待一秒
    // 重置LED状态
    digitalWrite(ledPinSuccess, LOW);
    digitalWrite(ledPinFail, LOW);
  }

  delay(100); // 短暂延时以减慢循环速度
}
