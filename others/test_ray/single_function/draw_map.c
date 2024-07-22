#include <mlx.h>
#include <stdlib.h>

#define MAPX 8      // map width
#define MAPY 8      // map height
#define MAPS 64     // map cube size

int map2d[MAPY][MAPX] = { // the map array. Edit to change level but keep the outer walls
    {1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1},
};

typedef struct s_image {
    void *image;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_image;

typedef struct s_data {
    void *mlx;
    void *win;
    t_image image;
    int map_size;
    int width_x;
    int height_y;
    struct {
        float x, y;
        float dx, dy;
    } player;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= data->width_x * data->map_size || y < 0 || y >= data->height_y * data->map_size) // Ensure coordinates are within bounds
        return;

    dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void draw_square(t_data *data, int x, int y, int color)
{
    int i, j;

    for (i = 0; i < data->map_size; i++)
    {
        for (j = 0; j < data->map_size; j++)
        {
            my_mlx_pixel_put(data, x + j, y + i, color);
        }
    }
}

void drawMap2D(t_data *data)
{
    int x, y;

    for (y = 0; y < data->height_y; y++)
    {
        for (x = 0; x < data->width_x; x++)
        {
            if (map2d[y][x] == 1)
                draw_square(data, x * data->map_size, y * data->map_size, 0xFFFFFF); // White color
            else
                draw_square(data, x * data->map_size, y * data->map_size, 0x000000); // Black color
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->image.image, 0, 0);
}

int draw_player(t_data *data)
{
    int x = (int)data->player.x;
    int y = (int)data->player.y;
    int size = 8;

    for (int i = -size; i < size; i++)
    {
        for (int j = -size; j < size; j++)
        {
            mlx_pixel_put(data->mlx, data->win, x + i, y + j, 0xFFFF00);
        }
    }
    mlx_pixel_put(data->mlx, data->win, x + data->player.dx * 20, y + data->player.dy * 20, 0xFFFF00);

    return (0);
}

int main()
{
    t_data data;

    data.mlx = mlx_init();
    data.width_x = MAPX;
    data.height_y = MAPY;
    data.map_size = MAPS;

    data.win = mlx_new_window(data.mlx, data.width_x * data.map_size, data.height_y * data.map_size, "2D Map");

    data.image.image = mlx_new_image(data.mlx, data.width_x * data.map_size, data.height_y * data.map_size);
    data.image.addr = mlx_get_data_addr(data.image.image, &data.image.bits_per_pixel, &data.image.line_length, &data.image.endian);

    data.player.x = 100; // Example player position
    data.player.y = 100;
    data.player.dx = 1;  // Example player direction
    data.player.dy = 0;

    drawMap2D(&data);
    draw_player(&data);

    mlx_loop(data.mlx);
    return (0);
}
