/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:52:29 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/13 18:43:47 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

/*
** -------------------------- ft_atoi ----------------------------
*/
int					ft_atoi(const char *nptr);

/*
** -------------------------- ft_bzero ---------------------------
*/
void				ft_bzero(void *s, size_t n);

/*
** -------------------------- ft_freetab -------------------------
*/
void				ft_freetab(void ***tab);

/*
** -------------------------- ft_isdigit -------------------------
*/
int					ft_isdigit(int c);

/*
** -------------------------- ft_memalloc ------------------------
*/
void				*ft_memalloc(size_t size);

/*
** -------------------------- ft_memset --------------------------
*/
void				*ft_memset(void *s, int c, size_t n);

/*
** -------------------------- ft_putchar_fd ----------------------
*/
void				ft_putchar_fd(char c, int fd);

/*
** -------------------------- ft_putchar -------------------------
*/
void				ft_putchar(char c);

/*
** -------------------------- ft_putendl_fd ----------------------
*/
void				ft_putendl_fd(char const *s, int fd);

/*
** -------------------------- ft_putendl -------------------------
*/
void				ft_putendl(char const *s);

/*
** -------------------------- ft_putstr_fd -----------------------
*/
void				ft_putstr_fd(char const *s, int fd);

/*
** -------------------------- ft_putstr --------------------------
*/
void				ft_putstr(char const *s);

/*
** -------------------------- ft_strchr --------------------------
*/
char				*ft_strchr(const char *s, int c);

/*
** -------------------------- ft_strdel --------------------------
*/
void				ft_strdel(char **as);

/*
** -------------------------- ft_strdup --------------------------
*/
char				*ft_strdup(const char *s);

/*
** -------------------------- ft_strjoin -------------------------
*/
char				*ft_strjoin(char const *s1, char const *s2);

/*
** -------------------------- ft_strjoinfree ---------------------
*/
char				*ft_strjoinfree(char const *s1, char const *s2, int wfree);

/*
** -------------------------- ft_strlen --------------------------
*/
size_t				ft_strlen(const char *s);

/*
** -------------------------- ft_strndup -------------------------
*/
char				*ft_strndup(const char *s, size_t n);

/*
** -------------------------- ft_strnlen -------------------------
*/
size_t				ft_strnlen(const char *s, size_t maxlen);

/*
** -------------------------- ft_strsplit ------------------------
*/
char				**ft_strsplit(char const *s, char c);

/*
** -------------------------- ft_strsub --------------------------
*/
char				*ft_strsub(const char *s1, unsigned int start, size_t len);

/*
** -------------------------- ft_words_count ---------------------
*/
int					ft_words_count(const char *str, char c);

#endif
