# fractol
![Screenshot](https://i.imgur.com/A9mhp9j.png)

Simple fractal rendering.

Written in C with minilibX.

### Supported fractals
* Mandelbrot
* Julia
* Burning ship

## How to use
Runs on linux and freeBSD.

### Dependencies (Debian)
	sudo apt update && sudo apt install gcc make xorg libxext-dev libbsd-dev

### Compiling & running
	make
	./fractol <arg>

### Controls
| Key | Description | Key | Description |
|:---:| ----------- |:---:| ----------- |
| WASD | move the view | Z | precision - |
| scroll | zoom | X | precision + |
| 1-3 | colour schemes | R | reset |
