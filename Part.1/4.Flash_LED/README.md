# Flash Light LED

[English](README.md) | [中文](README_zh.md)

## 1. Write the code

We assume that you have finished the [Part.1/3.Light_LED](../3.Light_LED/README.md) tutorial.

Now, we will make the LED flash.

Modify the code in `Src/main.c`:

```c

/* USER CODE BEGIN WHILE */
while (1)
{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_Delay(1000);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_Delay(1000);
}
/* USER CODE END 3 */

```

Or you can use `HAL_GPIO_TogglePin` function:

```c
while (1)
{
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(1000);
}
```

The `HAL_GPIO_TogglePin` function is used to toggle the pin state. The first parameter is the GPIO port, the second parameter is the GPIO pin.

Then build and flash the project. You can see the LED is flashing.
