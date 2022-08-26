For esp32 only:


gen_esp32part.py:
```txt
字段之间的空格会被忽略，任何以 # 开头的行（注释）也会被忽略。
CSV 文件中的每个非注释行均为一个分区定义。
每个分区的 Offset 字段可以为空，gen_esp32part.py 工具会从分区表位置的后面开始自动计算并填充该分区的偏移地址，同时确保每个分区的偏移地址正确对齐。
```
手动将 CSV 文件转换为二进制文件:
```bash
    python gen_esp32part.py input_partitions.csv binary_partitions.bin
```
手动将二进制文件转换为 CSV 文件:
```bash
    python gen_esp32part.py binary_partitions.bin input_partitions.csv
```
在标准输出（stdout）上，打印二进制分区表的内容（在运行 idf.py partition_table 时，我们正是这样打印上文展示的信息摘要的）:
```bash
    python gen_esp32part.py binary_partitions.bin
```

参考资料:
https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/partition-tables.html#name

nvs:是专门给 非易失性存储 (NVS) API 使用的分区。
```txt
用于存储每台设备的 PHY 校准数据（注意，并不是 PHY 初始化数据）。

用于存储 Wi-Fi 数据（如果使用了 esp_wifi_set_storage(WIFI_STORAGE_FLASH) 初始化函数）。

NVS API 还可以用于其他应用程序数据。

强烈建议您应为 NVS 分区分配至少 0x3000 字节空间。

如果使用 NVS API 存储大量数据，请增加 NVS 分区的大小（默认是 0x6000 字节）。
```

otadata的数据分区，用于保存 OTA 升级时需要的数据。启动加载器会查询该分区的数据，以判断该从哪个 OTA 应用程序分区加载程序。如果 “otadata” 分区为空，则会执行出厂程序。

APP分区:
```txt
app 分区的偏移地址必须要与 0x10000 (64K) 对齐，如果将偏移字段留空，gen_esp32part.py 工具会自动计算得到一个满足对齐要求的偏移地址。如果 app 分区的偏移地址没有与 0x10000 (64K) 对齐，则该工具会报错。

app 分区的大小和偏移地址可以采用十进制数、以 0x 为前缀的十六进制数，且支持 K 或 M 的倍数单位（分别代表 1024 和 1024*1024 字节）。
```


