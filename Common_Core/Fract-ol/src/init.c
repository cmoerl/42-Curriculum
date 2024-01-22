#include "../incl/fract-ol.h"
#include <stdlib.h>

t_img *init_img(t_fractol *fractol)
{
    // Add your implementation here
    // This function is responsible for initializing the image
    return NULL; // Replace with the actual implementation
}

t_hooks *init_hooks(char *real, char *imaginary)
{
    // Add your implementation here
    // This function is responsible for initializing the hooks
    return NULL; // Replace with the actual implementation
}

t_fractol *init_mandelbrot(void)
{
    t_fractol *fractol;

    fractol = malloc(sizeof(t_fractol));
    if (!fractol)
        exit(EXIT_FAILURE);
    fractol->name = ft_strdup("mandelbrot");
    if (!fractol->name)
        malloc_exit_fractol(fractol);
    fractol->mlx_ptr = mlx_init();
    if (!fractol->mlx_ptr)
        malloc_exit_fractol(fractol);
    fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
    if (!fractol->win_ptr)
        malloc_exit_fractol(fractol);
    fractol->img = init_img(fractol);
    if (!fractol->img)
        malloc_exit_fractol(fractol);
    fractol->hooks = init_hooks(NULL, NULL);
    if (!fractol->hooks)
        malloc_exit_fractol(fractol);
    return fractol;
}

t_fractol *init_julia(char *real, char *imaginary)
{
    t_fractol *fractol;

    fractol = malloc(sizeof(t_fractol));
    if (!fractol)
        exit(EXIT_FAILURE);
    fractol->name = ft_strdup("julia");
    if (!fractol->name)
        malloc_exit_fractol(fractol);
    fractol->mlx_ptr = mlx_init();
    if (!fractol->mlx_ptr)
        malloc_exit_fractol(fractol);
    fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
    if (!fractol->win_ptr)
        malloc_exit_fractol(fractol);
    fractol->img = init_img(fractol);
    if (!fractol->img)
        malloc_exit_fractol(fractol);
    fractol->hooks = init_hooks(real, imaginary);
    if (!fractol->hooks)
        malloc_exit_fractol(fractol);
    return fractol;
}
