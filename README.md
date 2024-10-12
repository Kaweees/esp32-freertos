```sh
ls /dev/cu.*
```

```sh
idf.py set-target esp32s3
idf.py build
idf.py -p /dev/cu.usbmodem1101 -b 115200 flash monitor
```

