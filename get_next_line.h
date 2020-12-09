/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:28:31 by anassif           #+#    #+#             */
/*   Updated: 2020/12/09 20:12:53 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int 	ft_strlen(const char *str);
char	*ft_stock(char *line, char *buff, int i);
int		get_next_line(char **line);
int		ft_count(char *str);

#endif
