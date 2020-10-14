

// 使用 Kvaser CANLIB 时，在文件开头，必须包含 #include <canlib.h>

void main(void)
{
    canHandle h;
    // 初始化驱动程序
    canInitializeLibrary();
    // 读 CAN 通道数目，获取通道句柄
    h = canOpenChannel(0, canWANT_EXCLUSIVE);
    if (h != canOK)
    {
        char msg[64];
        canGetErrorText((canStatus)h, msg, sizeof(msg));
        fprintf(stderr, "canOpenChannel failed (%s)\n", msg);
        exit(1);
    }
    // 设定通道参数
    canSetBusParams(h, BAUD_250K, 0);
    // 设定通道工作类型
    canSetBusOutputControl(h, canDRIVER_NORMAL);
    // 打开总线
    canBusOn(h);
    // 读 CAN 消息或写 CAN 消息
    canWrite(h, 123, "HELLO!", 6, 0);
    canWriteSync(h, 500);
    //  关闭总线
    canBusOff(h);
    // 关闭通道
    canClose(h);
}