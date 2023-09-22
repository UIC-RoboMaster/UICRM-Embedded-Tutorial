# UIC RoboMaster 嵌入式教程

[English](README.md) | [中文](README_zh.md)

UIC RoboMaster 战队的嵌入式系统学习教程，包括基本的开发技巧、STM32、PID 和一些基本的控制算法。

我们假设加入我们战队的人已经完成了 COMP1023 课程，所以我们不会介绍 C 语言的基础知识。如果你对 C 语言不熟悉，请先学习它。

## 目录

### Part.0 CS基础知识

1. [如何友好的查找资料/正确的搜索东西](Part.0/1.How_to_search/README_zh.md)
2. [Git的使用/GitHub/如何发起PR/如何合并分支](Part.0/2.How_to_use_git/README_zh.md)

### Part.1 STM32从入门到劝退

1. [安装环境](Part.1/1.Install_Environments/README_zh.md)
2. [原理图识别/新建工程](Part.1/2.New_Empty_Project/README_zh.md)
3. [点亮LED](Part.1/3.Light_LED/README_zh.md)
4. [闪烁LED](Part.1/4.Flash_LED/README_zh.md)
5. [断点/分析与调试](Part.1/5.BreakPoint/README_zh.md)
6. [按键输入（轮询方法）](Part.1/6.Key_Input/README_zh.md)
7. [按键输入（中断方法）+中断简介](Part.1/7.Key_Inturrupt/README_zh.md)
8. [定时器简介/使用定时器点亮LED](Part.1/8.Timer/README_zh.md)
9. 呼吸灯/servo/PWM输出
10. 蜂鸣器/频率计算
11. ADC
12. OS入门/FreeRTOS
13. 多线程初步+Flag的使用
14. I2C/OLED/MPU6050
15. UART/串口收发
16. [CAN/RM电机驱动](Part.1/16.CAN_and_Motor/README_zh.md)
17. SPI/存储器使用/BMI088
18. DMA

### Part.2 电控相关控制知识

1. 基础电路/D-Bus(自己实现一个反电路)
2. PID原理
3. 调PID
4. 麦克纳姆轮解算/全向轮解算
5. 卡尔曼滤波/AHRS/航向角获取
6. 串级PID
7. 云台控制
