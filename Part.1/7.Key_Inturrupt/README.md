# Key Inturrupt

[English](README.md) | [中文](README_zh.md)

## What is inturrupt?

In embedded systems, we often need to respond to external events. For example, when a button is pressed, we need to turn on the LED. In this case, we need to constantly read the button state in the main loop. This is called polling. However, this method is not efficient. We can use inturrupt to solve this problem.

Inturrupt is a mechanism that allows the CPU to respond to external events in time. When an external event occurs, the CPU will stop the current task and execute the corresponding inturrupt service routine. After the inturrupt service routine is executed, the CPU will return to the original task.

So we can use inturrupt to respond to external events. For example, when a button is pressed, we can use inturrupt to turn on the LED.

However, the programs in the inturrupt service routine should be as simple as possible. This is because the CPU will stop the current task when an inturrupt occurs. If the inturrupt service routine is too long, the CPU will spend too much time on the inturrupt service routine, and the main task will not be executed in time. This will cause the system to crash.

## Priority of inturrupt

In the STM32F103C8T6, there are 16 inturrupts. The priority of inturrupts is from 0 to 15. The smaller the number, the higher the priority. The inturrupt with the highest priority is the reset inturrupt. The inturrupt with the lowest priority is the systick inturrupt.

The higher priority inturrupt can interrupt the lower priority inturrupt. For example, if the systick inturrupt is executing, and the key inturrupt occurs, the key inturrupt will interrupt the systick inturrupt.

## Fault Inturrupt

In addition to the normal inturrupt, there is also a fault inturrupt. The fault inturrupt is used to handle the fault. For example, when the stack overflow occurs, the fault inturrupt will be executed.
In General, When the fault inturrupt occurs, the system will stop forever (It has got an `while(1)` loop in the fault inturrupt service routine). So we should avoid the fault inturrupt, like the stack overflow and the memory access error.
