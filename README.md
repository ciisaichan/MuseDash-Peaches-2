# MuseDash-Peaches-2
开源的触摸式音游控制器，可以兼容使用DFJK按键的下落式音游。

### 视频
<https://www.bilibili.com/video/BV165411L7LT>

### 目录/文件
- [images](https://github.com/ciisaichan/MuseDash-Peaches-2/tree/main/images "images") - 介绍用图片资源
- [mush_dash_peaches2](https://github.com/ciisaichan/MuseDash-Peaches-2/tree/main/mush_dash_peaches2 "mush_dash_peaches2") - Arduino单片机源代码
- [pcb_gerber](https://github.com/ciisaichan/MuseDash-Peaches-2/tree/main/pcb_gerber "pcb_gerber") - PCB生产文件
- [shell](https://github.com/ciisaichan/MuseDash-Peaches-2/tree/main/shell "shell") - 用于外壳切割的矢量图片
- [BOM.xlsx](https://github.com/ciisaichan/MuseDash-Peaches-2/blob/main/BOM.xlsx "BOM.xlsx") - 配件配单表
- [schematic.pdf](https://github.com/ciisaichan/MuseDash-Peaches-2/blob/main/schematic.pdf "schematic.pdf") - 电路原理图

### PCB预览图/原理图
![PCB预览图](https://raw.githubusercontent.com/ciisaichan/MuseDash-Peaches-2/main/images/pcb2.jpg)
![电路原理图](https://raw.githubusercontent.com/ciisaichan/MuseDash-Peaches-2/main/images/sch.jpg)

### 功能
此版本配备4个分别对应DFJK按键的触摸电极，就是开发板接线柱的4个接口，
同时还有74HC595驱动的8个LED灯，可以自己进行编程，
也可以使用剩余的IO口加入自己的功能，

### 使用方法
将开发板接线柱上方橘色的把手往前推，接入导线再松开，之后可以将导线接到任意导体（如水果，锡箔纸）用来充当按键，将开发板与电脑连接后会被识别为HID键盘，此时触摸连接的导体就会发送对应的按键信号到电脑上，可以用记事本之类输入文本的地方进行测试。

### 制作指南
如果觉得此版本难度较大可以选择之前的版本：
<https://github.com/ciisaichan/MuseDash-Peaches>


1. 此版本因为涉及贴片焊接，所以需要工具以及焊接技能，可以使用PCB厂家提供的SMT贴片服务，这样到手就是成品，比较特殊的零件就是 "4p免螺丝接线端子" 需要自己单独购买和焊接。
2. 硬件部分制作完成后需要对单片机烧写bootloader才可以用Arduino IDE编程。[bootloader烧写教程](https://blog.csdn.net/sysjtlwx/article/details/73824903 "bootloader烧写教程")
3. bootloader烧写完成后将开发板通过USB连接电脑，打开Arduino IDE并打开源代码，选择开发板为 "Arduino Leonardo"并选择开发板对应端口，点击 "上传" 即可。（如果编译错误请安装 "CapacitiveSensor" 库）
4. 开发板固定孔以及外壳固定孔的直径为2.5mm，如需要请选择2.5mm直径的螺丝
