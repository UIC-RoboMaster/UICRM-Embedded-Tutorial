# Timer

[English](README.md) | [中文](README_zh.md)

## What is timer?

In embedded systems, we often need to perform some tasks periodically. For example, we need to read the temperature every 1 second. In this case, we can use timer to solve this problem.

Timer is a hardware device that can generate periodic interrupts. When the timer generates an interrupt, the CPU will stop the current task and execute the corresponding interrupt service routine. After the interrupt service routine is executed, the CPU will return to the original task.

So we can use timer to perform some tasks periodically. For example, we can use timer to read the temperature every 1 second.

Also, we can use timer to generate PWM signal. For example, we can use timer to control the brightness of the LED.
