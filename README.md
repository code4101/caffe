## 说明

该项目来源于：https://github.com/Microsoft/caffe（commit：f51294f）

## 改动

- 改为WIN10 + CUDA8.0 + cuDNN5的配置环境
	* 我用的显卡是GTX980Ti,对于非"GTX960, 970, 980, Titan X"系列的显卡，记得要改CudaArchitecture。
- 增加wkDir工作目录
- 不忽略.user文件
- 增加mycaffe动态库接口项目，及对应的mytest测试项目
- 其他一些小改动
