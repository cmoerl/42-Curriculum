#include "../incl/fract-ol.h"
#include <stdlib.h>

t_img *init_img(void *mlx_ptr, int width, int height)
{
    t_img *img;

    img = malloc(sizeof(t_img));
    if (!img)
        return (NULL);
    img->img_ptr = mlx_new_image(mlx_ptr, width, height);
    if (!img->img_ptr)
        return (NULL);
    img->pxl = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
    if (!img->pxl)
        return (NULL);
    return (img);
}

t_hooks *init_hooks(char *real, char *imaginary)
{
    // Add your implementation here
    // This function is responsible for initializing the hooks
    return NULL; // Replace with the actual implementation
}

t_fractol *init_fract(char *real, char *imaginary)
{
    t_fractol *fractol;

    fractol = malloc(sizeof(t_fractol));
    if (!fractol)
        exit(EXIT_FAILURE);
    if (!(fractol->name = ft_strdup("julia")))
        malloc_exit_fractol(fractol);
    if (!(fractol->mlx_ptr = mlx_init()))
        malloc_exit_fractol(fractol);
    if (!(fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, fractol->name)))
    {
        mlx_destroy_display(fractol->mlx_ptr);
        malloc_exit_fractol(fractol);
    }
    if (!(fractol->img = init_img(fractol->mlx_ptr, WIDTH, HEIGHT)))
    {
        mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
        mlx_destroy_display(fractol->mlx_ptr);
        malloc_exit_fractol(fractol);
    }
    if (!(fractol->hooks = init_hooks(real, imaginary)))
        malloc_exit_fractol(fractol);
    return fractol;
}
