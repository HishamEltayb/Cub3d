#include <math.h>
#include <mlx.h>

#define mapX  8      // map width
#define mapY  8      // map height
#define mapS 64      // map cube size

int map[]=           // the map array. Edit to change level but keep the outer walls
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,	
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
        float angle;
    } player;
} t_data;

float degToRad(float a) { return a * M_PI / 180.0; }
int FixAng(int a) { if (a > 359) a -= 360; if (a < 0) a += 360; return a; }

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= data->width_x * data->map_size || y < 0 || y >= data->height_y * data->map_size) // Ensure coordinates are within bounds
        return;

    dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = fmaxf(fabsf(dx), fabsf(dy));
    dx /= steps;
    dy /= steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        my_mlx_pixel_put(data, x, y, color);
        x += dx;
        y += dy;
    }
}

void drawRays2D(t_data *data)
{
    int r, mx, my, mp, dof;
    float rx, ry, ra, xo, yo, dis_h;

    ra = FixAng(data->player.angle + 30); // ray set back 30 degrees

    for (r = 0; r < 60; r++) {
        //---Horizontal---
        dof = 0; dis_h = 100000;
        float Tan = tan(degToRad(ra));
        if (sin(degToRad(ra)) > 0.001) {
            ry = (((int)data->player.y >> 6) << 6) - 0.0001;
            rx = (data->player.y - ry) * Tan + data->player.x;
            yo = -64; xo = -yo * Tan;
        } else if (sin(degToRad(ra)) < -0.001) {
            ry = (((int)data->player.y >> 6) << 6) + 64;
            rx = (data->player.y - ry) * Tan + data->player.x;
            yo = 64; xo = -yo * Tan;
        } else {
            rx = data->player.x; ry = data->player.y; dof = 8;
        }

        while (dof < 8) {
            mx = (int)(rx) >> 6; my = (int)(ry) >> 6; mp = my * mapX + mx;
            if (mp > 0 && mp < mapX * mapY && map[mp] == 1) {
                dof = 8; dis_h = cos(degToRad(ra)) * (rx - data->player.x) - sin(degToRad(ra)) * (ry - data->player.y);
            } else {
                rx += xo; ry += yo; dof += 1;
            }
        }

        int ca = FixAng(data->player.angle - ra); dis_h = dis_h * cos(degToRad(ca)); // fix fisheye
        int lineH = (mapS * 320) / dis_h; if (lineH > 320) { lineH = 320; } // line height and limit
        int lineOff = 160 - (lineH >> 1); // line offset

        draw_line(data, r * 8 + 530, lineOff, r * 8 + 530, lineOff + lineH, 0x00FF00); // draw vertical wall

        ra = FixAng(ra - 1); // go to next ray
    }
}

int main()
{
    t_data data;

    data.mlx = mlx_init();
    data.width_x = mapX;
    data.height_y = mapY;
    data.map_size = mapS;

    data.win = mlx_new_window(data.mlx, data.width_x * data.map_size, data.height_y * data.map_size, "Raycasting");

    data.image.image = mlx_new_image(data.mlx, data.width_x * data.map_size, data.height_y * data.map_size);
    data.image.addr = mlx_get_data_addr(data.image.image, &data.image.bits_per_pixel, &data.image.line_length, &data.image.endian);

    data.player.x = 300; // Example player position
    data.player.y = 300;
    data.player.angle = 0;

    drawRays2D(&data);

    mlx_put_image_to_window(data.mlx, data.win, data.image.image, 0, 0);
    mlx_loop(data.mlx);
    return (0);
}
