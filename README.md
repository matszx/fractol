# fractol
# Simple fractal rendering
![Screenshot](https://i.imgur.com/A9mhp9j.png)

Written in C with minilibX. Runs on linux and freeBSD.

### Supported fractals
* Mandelbrot
* Julia
* Burning ship

## Dependencies
```
sudo apt update && sudo apt install gcc make xorg libxext-dev libbsd-dev
```

## How to use
To compile:
```
make
```
To run:
```
./fractol <fractal name>
```
For the Julia set:
```
./fractol julia <r> <i>
```