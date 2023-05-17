# remotescreen

FFMPEG 构建


./ffmpeg -f fbdev -i /dev/fb0 -r 24 output.avi

ffmpeg -f fbdev -i /dev/fb0 -r 24 -c:v libx264 -b:v 500k output.avi