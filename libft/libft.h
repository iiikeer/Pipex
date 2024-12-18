/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:14:23 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/12 11:47:54 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

//Verificacion y Conversion de Caracteres
int			ft_toupper(int c);

//Manipulacion de Cadenas
size_t		ft_strlen(const char *str);
void		ft_strcpy(char *dst, char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);

//Escritura de datos
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int nbr, int fd);
void		ft_putstr_fd(char *s, int fd);

//Printf
int			ft_printf(char const *str, ...);
int			ft_switch_case(va_list args, const char c);
int			ft_printf_char(char c);
int			ft_printf_str(char *str);
int			ft_printf_pnt(unsigned long long int ptr);
int			ft_printf_nbr(int nbr);
int			ft_printf_uns(unsigned int nbr);
int			ft_printf_hex(unsigned int nbr, int upper);

//Get Next Line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
char		*read_line(int fd, char *buffer, char *line);
char		*get_line(char *line, char *buffer);
void		clean_line(char *buffer);

#endif
