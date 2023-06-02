# 闪烁 LED

[English](README.md) | [中文](README_zh.md)

我们假设你已经完成了[Part.1/3.Light_LED](../3.Light_LED/README.md)教程。

现在，我们将让 LED 闪烁。

修改 `Src/main.c` 中的代码：

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

或者你可以使用 `HAL_GPIO_TogglePin` 函数：

```c
while (1)
{
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(1000);
}
```

函数 `HAL_GPIO_TogglePin` 用于切换引脚状态。第一个参数是 GPIO 端口，第二个参数是 GPIO 引脚。

然后编译并烧录项目。你可以看到 LED 正在闪烁。
