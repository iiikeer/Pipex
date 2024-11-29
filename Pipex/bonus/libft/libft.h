/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:14:23 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 16:58:34 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

//Verificacion y Conversion de Caracteres
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isspace(int c);

//Manipulacion de Memoria
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

//Manipulacion de Cadenas
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
void		ft_strcat(char *dest, const char *src);
void		ft_strcpy(char *dst, char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *str, const char *to_find, size_t n);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);

//Asignacion de Memoria
void		*ft_calloc(size_t nmemb, size_t size);

//Escritura de datos
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int nbr, int fd);
void		ft_putstr_fd(char *s, int fd);

//Conversion de Datos
char		*ft_itoa(int nbr);
int			ft_atoi(const char *str);
long int	ft_atol(const char *str);

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

char	*get_next_line(int fd);
char	*ft_read_next_line(int fd, char *next_line);
char	*ft_get_line(char *next_line);
char	*ft_clean_line(char *next_line);
char	*ft_free_gnl(char **str);

//Manipulacion de Listas
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);

#endif
