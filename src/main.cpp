// 定义交通灯引脚
#define phase_1_green 2
#include <Arduino.h>
#define phase_1_yellow 3
#define phase_1_red 4
#define phase_2_green 5
#define phase_2_yellow 6
#define phase_2_red 7

// --------------------------
// 城市道路标准配置（已更新）
// --------------------------
int cycle_time_sec = 60;      // 总周期建议 60 秒
int yellow_time_sec = 3;      // 城市标准黄灯 3 秒
int all_red_time_sec = 2;     // 全红安全时长 2 秒
float green_time_ratio = 0.5; // 两个方向绿灯分配（0.5 为对等）

// 内部计算变量
unsigned long yellow_time_ms;
unsigned long all_red_time_ms;
unsigned long green_phase1_ms;
unsigned long green_phase2_ms;

void setup() {
  pinMode(phase_1_green, OUTPUT);
  pinMode(phase_1_yellow, OUTPUT);
  pinMode(phase_1_red, OUTPUT);
  pinMode(phase_2_green, OUTPUT);
  pinMode(phase_2_yellow, OUTPUT);
  pinMode(phase_2_red, OUTPUT);

  // 预计算时间（毫秒）
  yellow_time_ms = yellow_time_sec * 1000;
  all_red_time_ms = all_red_time_sec * 1000;
  
  // 绿灯总时长 = 总周期 - (2次黄灯) - (2次全红)
  long total_green_ms = (cycle_time_sec * 1000L) - (yellow_time_ms * 2) - (all_red_time_ms * 2);
  green_phase1_ms = total_green_ms * green_time_ratio;
  green_phase2_ms = total_green_ms - green_phase1_ms;

  // 初始状态：双向红灯，安全起步
  digitalWrite(phase_1_red, HIGH);
  digitalWrite(phase_2_red, HIGH);
  delay(2000);
}

void loop() {
  // --- 相位 1 通行 ---
  digitalWrite(phase_1_red, LOW);
  digitalWrite(phase_1_green, HIGH);
  delay(green_phase1_ms);

  // --- 相位 1 黄灯（清空路口） ---
  digitalWrite(phase_1_green, LOW);
  digitalWrite(phase_1_yellow, HIGH);
  delay(yellow_time_ms);

  // --- 全红阶段 1（最安全的设计） ---
  digitalWrite(phase_1_yellow, LOW);
  digitalWrite(phase_1_red, HIGH); 
  // 此时 phase_1_red 和 phase_2_red 都是 HIGH
  delay(all_red_time_ms);

  // --- 相位 2 通行 ---
  digitalWrite(phase_2_red, LOW);
  digitalWrite(phase_2_green, HIGH);
  delay(green_phase2_ms);

  // --- 相位 2 黄灯（清空路口） ---
  digitalWrite(phase_2_green, LOW);
  digitalWrite(phase_2_yellow, HIGH);
  delay(yellow_time_ms);

  // --- 全红阶段 2 ---
  digitalWrite(phase_2_yellow, LOW);
  digitalWrite(phase_2_red, HIGH);
  // 此时双向变红，准备进入下一个周期
  delay(all_red_time_ms);
}