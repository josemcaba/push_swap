/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:00:46 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/09 20:35:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_flags
{
	char	specifier;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
	int		nflags;
	int		negative;
}	t_flags;

int		ft_printf(char const *format, ...);
int		pf_char_convert(va_list *args, t_flags *flags);
int		pf_char_convert_narg(t_flags *flags);
int		pf_str_convert(va_list *args, t_flags *flags);
int		pf_int_convert(va_list *args, t_flags *flags);
void	pf_fill_pad_int(char **pad, char *nbr, t_flags *flags);
void	pf_add_prfx_int(char **pad, int *nbr_len, t_flags *flags, int no_zero);
int		pf_alloc_pad_int(char **pad, char *nbr, t_flags *flags);
void	pf_add_precision(char **pad, int *nbr_len, t_flags *flags, int zero);
void	pf_add_width_int(char **pad, int nbr_len, t_flags *flags);
int		pf_uint_convert(va_list *args, t_flags *flags);
int		pf_hex_convert(va_list *args, t_flags *flags);
void	pf_flags_read(t_flags *flags, char const *format);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *s);
char	*ft_htoa(size_t n, int specifier);
char	*ft_uitoa(unsigned int n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 81
# endif

# define FD_MAX 2048

typedef struct s_glist
{
	char			*content;
	struct s_glist	*next;
	int				nl_flag;
	size_t			nl;
	size_t			len;
}	t_glist;

char	*get_next_line(int fd);
t_glist	*lst_new_node(char *content, int nl_flag, size_t len);
void	lst_add_node(t_glist **list, t_glist *node);
void	lst_free(t_glist **lst);
void	mem_cpy_str(char *dst, char *src, size_t len);
size_t	str_len(char *str, int *nl_flag);

#endif
