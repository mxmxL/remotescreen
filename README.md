# remotescreen


```
# 交叉编译

source /opt/fsl-imx-wayland/4.1.15-2.1.0/environment-setup-cortexa9hf-neon-poky-linux-gnueabi

# libx264 交叉编译
./configure --sysroot=/opt/fsl-imx-wayland/4.1.15-2.1.0/sysroots/cortexa9hf-neon-poky-linux-gnueabi \
            --host=arm-poky-linux-gnueabi --cross-prefix=arm-poky-linux-gnueabi- \
            --extra-cflags="-march=armv7-a -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a9 -rdynamic" \
            --disable-asm --prefix="/opt/fsl-imx-wayland/4.1.15-2.1.0/sysroots/cortexa9hf-neon-poky-linux-gnueabi/usr" --enable-shared --enable-static

# ffmpeg 交叉编译
export PKG_CONFIG_PATH=/opt/fsl-imx-wayland/4.1.15-2.1.0/sysroots/cortexa9hf-neon-poky-linux-gnueabi/usr/lib/pkgconfig:${PKG_CONFIG_PATH}
./configure --sysroot=/opt/fsl-imx-wayland/4.1.15-2.1.0/sysroots/cortexa9hf-neon-poky-linux-gnueabi \
            --enable-cross-compile --arch=armv7l --cpu=cortex-a9 --target-os=linux --cross-prefix=arm-poky-linux-gnueabi- \
            --extra-cflags="-march=armv7-a -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a9 -rdynamic" \
            --disable-asm --prefix="/home/dengdh/mysource/ffmpeg-6.0/install" \
            --enable-version3 --enable-nonfree --enable-gpl --enable-libx264 \
            --pkg-config=/opt/fsl-imx-wayland/4.1.15-2.1.0/sysroots/x86_64-pokysdk-linux/usr/bin/x86_64-pokysdk-linux-gnu-pkg-config
```



FFMPEG 构建


./ffmpeg -f fbdev -i /dev/fb0 -r 24 output.avi

ffmpeg -f fbdev -i /dev/fb0 -r 24 -c:v libx264 -b:v 500k output.avi