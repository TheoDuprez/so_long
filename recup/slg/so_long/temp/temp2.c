/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:55:47 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/21 15:57:03 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

// Fermer correctement le jeu avec la porte, echap et la croix
// Checker d'ou viennes les problemes sur valgrind
// Algo de pathfinding
// Normer le tout
// Afficher les pas sur la fenetre
//
// Faire le makefile (avec couleurs)

/*
S_slg est la structure du projet, qui va contenir :
- mlx : l'instance de la MLX
- mlx_win : l'addresse de la window
- mlx_img : l'addresse de l'image
- str : la map une fois parsée
- x : la largeur
- y : la hauteur
- i : le nombre d'objets sur la map
*/

typedef struct s_slg
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	**str;
	int		x;
	int		y;
	int		i;
}	t_slg;

/*
Convert_pxl va compter le nombre de case de largeur (x) et de hauteur (y),
puis les multiplier par la taille de la texture d'une case pour les donner
a mlx_new_window afin de lui donner la bonne taille de fenetre
*/

int	convert_pxl(char **str, int n)
{
	int	x;
	int	y;

	x = 0;
	while (str[x])
	{
		y = 0;
		while (str[x][y] && str[x][y] != '\n')
			y++;
		x++;
	}
	if (n == 0)
		return (y * 200);
	return (x * 200);
}

/*
What_texture va checker si :
- Notre case est un '1' : on affiche une box en bois
- Sinon : on affiche le sol
Ensuite, si notre case est 'E', 'P' ou 'C', on affiche par dessus :
- Si 'E' et que 'C' != 0: la porte (fermée)
- Sinon si 'E' et que 'C' == 0: la porte (ouverte)
- Sinon si 'C' : une orb d'ultimate
- Sinon si 'P' : reyna sans ult
*/

void	what_texture(char c, int x, int y, t_slg slg)
{
	int		img_w;
	int		img_h;
	void	*img;
	void	*mlx;
	void	*mlx_win;

	img = slg.mlx_img;
	mlx = slg.mlx;
	mlx_win = slg.mlx_win;
	if (c == '1')
		img = mlx_xpm_file_to_image(mlx, "xpm/wood.xpm", &img_w, &img_h);
	else
		img = mlx_xpm_file_to_image(mlx, "xpm/ground.xpm", &img_w, &img_h);
	mlx_put_image_to_window(mlx, mlx_win, img, x * 200, y * 200);
	if (c == 'E' && slg.i != 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/door_c.xpm", &img_w, &img_h);
	else if (c == 'E' && slg.i == 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/door_o.xpm", &img_w, &img_h);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(mlx, "xpm/ult_orb.xpm", &img_w, &img_h);
	else if (c == 'P' && slg.i != 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/reyna.xpm", &img_w, &img_h);
	mlx_put_image_to_window(mlx, mlx_win, img, x * 200, y * 200);
}

/*
Print_texture recupere la map passée en argument a so_long,
et va parser la map afin de choisir la texture a afficher grace a what_texture.
*/

void	print_texture(char **str, t_slg slg)
{
	int		x;
	int		y;

	y = 0;
	slg.i = 1;
	while (str[y])
	{
		x = 0;
		while (str[y][x] && str[y][x] != '\n')
		{
			what_texture(str[y][x], x, y, slg);
			x++;
		}
		y++;
	}
}

/*
Number of collectible va parser la map t_slg->str et compter le nombre de collectibles
sur la map et donne la valeur a slg->i
*/

void	number_of_collectible(t_slg *slg)
{
	int	x;
	int	y;

	x = 0;
	slg->i = 0;
	while (slg->str[x])
	{
		y = 0;
		while (slg->str[x][y] && slg->str[x][y] != '\n')
		{
			if (slg->str[x][y] == 'C')
				slg->i++;
			y++;
		}
		x++;
	}
}

/*
Player_position va parser slg->str et chercher ou est le char 'E' afin
de trouver la sortie et la stocker dans slg->x et slg->y
*/

void	exit_position(t_slg *slg)
{
	slg->y = 0;
	slg->x = 0;
	while (slg->str[slg->x])
	{
		slg->y = 0;
		while (slg->str[slg->x][slg->y])
		{
			if (slg->str[slg->x][slg->y] == 'E')
				return ;
			slg->y++;
		}
		slg->x++;
	}
}

/*
Player_position va parser slg->str et chercher ou est le char 'P' afin
de trouver le point de depart du joueur et le stocker dans slg->x et slg->y
*/

void	player_position(t_slg *slg)
{
	slg->y = 0;
	slg->x = 0;
	while (slg->str[slg->x])
	{
		slg->y = 0;
		while (slg->str[slg->x][slg->y])
		{
			if (slg->str[slg->x][slg->y] == 'P')
				return ;
			slg->y++;
		}
		slg->x++;
	}
}

/*
Replace_char va remplacer le char 'P' ou 'C' par '0'
- Si le char est 'P' on le remplace par '0'
- Si le char est 'C', on lui donne egalement '0', on decremente le nb d'orbs collectées,
on print la texture sol pour remplacer l'orb
- S'il n'y a plus d'orb, on donne a slg->x et slg->y (em les mettant dans des temps au prealable) la position
de 'E' pour afficher la texture de la porte ouverte
*/

void	replace_char(t_slg *slg)
{
	int	temp_x;
	int	temp_y;

	if (slg->str[slg->x][slg->y] == 'P')
		slg->str[slg->x][slg->y] = '0';
	else if (slg->str[slg->x][slg->y] == 'C')
	{
		slg->str[slg->x][slg->y] = '0';
		slg->i--;
		if (slg->i == 0)
		{
			temp_x = slg->x;
			temp_y = slg->y;
			exit_position(slg);
			what_texture(slg->str[slg->x][slg->y], slg->y, slg->x, *slg);
			slg->x = temp_x;
			slg->y = temp_y;
		}
		what_texture(slg->str[slg->x][slg->y], slg->y, slg->x, *slg);
	}
}

/*
Move_player direction va deplacer le personnage dans la map en remplacant :
- le char sur la position actuelle (si 'C' ou 'P') par un char '0' pour le transformer en sol (grace a replace_char)
- on choisi le personnage a afficher a direction + 1 (ult ou non selon le nb d'orb restante)
- les textures sur la position actuelle pour enlever le personnage et l'afficher a direction + 1 avec mlx_put_image_to_window
*/

void	move_player_direction(int keycode, t_slg *slg, int img_w, int img_h)
{
	void	*img;
	void	*mlx;
	void	*mlx_win;

	img = slg->mlx_img;
	mlx = slg->mlx;
	mlx_win = slg->mlx_win;
	replace_char(slg);
	if (slg->i != 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/reyna.xpm", &img_w, &img_h);
	else
		img = mlx_xpm_file_to_image(mlx, "xpm/reyna_ult.xpm", &img_w, &img_h);
	if (keycode == 2 && slg->str[slg->x][slg->y + 1] != '1')
		what_texture(slg->str[slg->x][slg->y], slg->y++, slg->x, *slg);
	else if (keycode == 1 && slg->str[slg->x + 1][slg->y] != '1')
		what_texture(slg->str[slg->x][slg->y], slg->y, slg->x++, *slg);
	else if (keycode == 0 && slg->str[slg->x][slg->y - 1] != '1')
		what_texture(slg->str[slg->x][slg->y], slg->y--, slg->x, *slg);
	else if (keycode == 13 && slg->str[slg->x - 1][slg->y] != '1')
		what_texture(slg->str[slg->x][slg->y], slg->y, slg->x--, *slg);
	else
		return ;
	replace_char(slg);
	mlx_put_image_to_window(mlx, mlx_win, img, slg->y * 200, slg->x * 200);
}

/*
Ft_check_side va checker si a coté de la touche appuyée il y a un mur (dans la meme direction que le touche)
*/

int	ft_check_side(int keycode, t_slg *slg)
{
	if (keycode == 2 && slg->str[slg->x][slg->y + 1] != '1')
		return (1);
	else if (keycode == 1 && slg->str[slg->x + 1][slg->y] != '1')
		return (1);
	else if (keycode == 0 && slg->str[slg->x][slg->y - 1] != '1')
		return (1);
	else if (keycode == 13 && slg->str[slg->x - 1][slg->y] != '1')
		return (1);
	return (0);
}

/*
Move_player va :
- compter le nombre d'orb sur la map au premier appel (grace a static int i)
- donner a t_slg.x et t_slg.y les coordonnées du personnage au premier appel
- compter et afficher le nombre de pas (si le personnage ne se deplace pas dans des murs)
- faire se deplacer le personnage dans la map grace a move_player_direction
*/

void	move_player(int keycode, t_slg *slg)
{
	int			img_w;
	int			img_h;
	static int	i;
	static int	nb_move;

	if (i == 0)
	{
		number_of_collectible(slg);
		player_position(slg);
	}
	i++;
	if (ft_check_side(keycode, slg))
	{
		nb_move++;
		printf("nb = %d\n", nb_move);
	}
	move_player_direction(keycode, slg, img_w, img_h);
}

/*
Ft_move est appelée par mlx_hook, elle permet :
- de faire se déplacer le joueur
- de fermer la fenêtre si le joueur appui sur echap (keycode 53) ou si
le personnage a recuperer toutes les orbs d'ult et qu'il est sur la porte
*/

int	ft_move(int keycode, t_slg *slg)
{
	move_player(keycode, slg);
	if (keycode == 53 || (slg->str[slg->x][slg->y] == 'E' && slg->i == 0))
	{
		mlx_destroy_window(slg->mlx, slg->mlx_win);
		exit((int)slg->mlx);
	}
	return (0);
}

/*
- Pour commencer, on appele mlx_init qui nous permet de nous connecter
au systeme graphique correct et retourne un 'void *' qui est l'emplacement
de notre instance MLX actuelle.
- On donne ensuite a x et y la largeur et hauteur respectivement
multipliée par la taille d'une seule texture pour donner la taille totale
a mlx_new_window.
- On appele ensuite print_texture pour afficher une premiere fois la map
avec le personnage au point de depart.
- On appele ensuite mlx_hook pour interargir avec les touches.
- Et enfin, mlx_loop pour afficher le rendu a l'ecran.
*/

void	so_long(char **str)
{
	t_slg	slg;
	int		x;
	int		y;

	x = convert_pxl(str, 0);
	y = convert_pxl(str, 1);
	slg.mlx = mlx_init();
	slg.mlx_win = mlx_new_window(slg.mlx, x, y, "so_long");
	print_texture(str, slg);
	slg.str = str;
	mlx_hook(slg.mlx_win, 2, 0, ft_move, &slg);
	mlx_loop(slg.mlx);
}
