/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:59:17 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/03 12:45:42 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int check_config(char *argv)
{
	
}
int check_input(int argc, char *argv)
{
	if (!argv || strlen(argv) < 5 || strcmp(argv + strlen(argv) - 4, ".cub") != 0)
	{
		fprintf(stderr, "Error: Invalid file extension. Expected '.cub'.\n");
		return (1);
	}
	int fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: File does not exist.\n");
		return (1);
	}
	close(fd);
	if (check_config(argv) != 0)
	{
		fprintf(stderr, "Error: Invalid configuration in the .cub file.\n");
		return (1);
	}
	return (0);
}