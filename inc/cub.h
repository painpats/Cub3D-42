#ifndef CUB_H
# define CUB_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "data.h"

// PARSING ////////////////////////////////////////////////
//-----parsing.c OK
int		check_open_files(char *file);
void	check_ext(char *files_name, char *ext);
int		check_map(char **content_file);
int		check_charinmap(char *content_map);
//-----extract_map.c OK
char	**get_map_cub(char **map);
char	**get_map(char **file);
//-----check_walls.c OK
void	check_walls(t_data *data); // function too long
void	check_surrounding(t_data *data, int y_pos, int x_pos);
//-----check_case.c OK
int		check_case(char c);
int		check_case_wall(char c);
//-----take_data.c OK
void	take_data(t_data *data);
int		take_rgb(t_data *data);
int		take_texture(t_data *data);
//-----rgb.c OK
void	check_rgb_parameters(char *str, t_data *data, char id);
void	check_rgb_values(t_data *data);
int		register_rgb(char *str, t_data *data);
//-----textures.c OK
int		checkif_textures(char *content_file, int i);
int		get_itextures(char *content_file, int i);
void	register_texture(char *str, t_data *data, char *cardinal_point);

// UTILS //////////////////////////////////////////////////
//-----init.c OK
void	init_parse(t_parse *parse);
void	init_texture(t_texture *texture);
void	init_data(t_data *data);
void	init_data(t_data *data);
void	pixel_to_img(t_data *data, int j, double ray_len, double angle);
//-----read.c OK
char	**read_file(int fd);
char	**check_and_split(char *str);
void	check_double_n(char **str, int *i);
int		rgbint(int red, int green, int blue, int a);
//-----ft_salloc.c OK
void	*ft_salloc(size_t lines, size_t lenght);
//-----ft_len.c OK
int		len_sstr(char **sstr);
size_t	len_longest_line(char **sstr);
//-----print.c OK
void	print_sstr(char **sstr);
//-----ft_strcpy_woz.c OK
void	ft_strcpy_woz(char **str, char *cpy);
//-----print_error.c OK
void	print_error(char *str);
void	print_error_free_str(char *str, char *clean);
void	print_error_free_sstr(char *str, char **content);

//-----print_error_free.c OK
void	print_error_free(char *str, t_data *data);
int		open_file(char *file);
//-----free.c OK
void	free_sstr(char **sstr);
void	free_all(t_data *data);

void	set_player_facing(t_data *data, char c);
int		is_player_pos(t_data *data, char *map_tab, int *x, int *y);
int		map_reader(t_data *data);

void	ft_hook(void *param);
void	step_forward(t_data *data);
void	step_backward(t_data *data);
void	step_left(t_data *data);
void	step_right(t_data *data);

// LE CUB //////////////////////////////////////////////////
// le_cub.c
void	display_img(void *param);
void	print_img(t_data *data);
double	correct_angle(double angle);
void	cub(t_data *data);
void	ray_casting(double *ray_len, double x, double y, double a);

#endif
