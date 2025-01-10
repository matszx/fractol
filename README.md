# fractol
![Screenshot](https://i.imgur.com/A9mhp9j.png)

Simple fractal rendering.

Written in C with minilibX. Runs on linux and freeBSD.

### Supported fractals
* Mandelbrot
* Julia
* Burning ship

## How to use

### Dependencies (Debian)
	sudo apt update && sudo apt install gcc make xorg libxext-dev libbsd-dev

### Compiling
	make

### Running
	./fractol <fractal name>
Add ***r*** and ***i*** values for the Julia set.

### Controls
| Key | Description | Key | Description |
|:---:| ----------- |:---:| ----------- |
| WASD | move the view | Z | decrease precision |
| scroll wheel | zoom in/out | X | increase precision |
| 1-3 | change color scheme | R | reset window |
