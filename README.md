<h1>Transmission</h1>

[<img src="https://img.youtube.com/vi/TpM7fpkYzZQ/hqdefault.jpg" width="100%">](https://youtu.be/TpM7fpkYzZQ)

<p>

2020/05/11

Author: Victor De la Luz

email: vdelaluz@enesmorelia.unam.mx

License: GNU/GPL

Languaje: C

Compile: make

Run: ./transm > view2D.dat

Create visualization:

./view2D.py

ffmpeg   -framerate 60   -pattern_type glob   -i 'animation/*.png'   -r 15   -vf scale=512:-1 ../transmission.mp4 ;
</p>