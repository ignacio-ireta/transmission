<h1>Transmission</h1>

<iframe width="560" height="315" src="https://www.youtube.com/embed/TpM7fpkYzZQ" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

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