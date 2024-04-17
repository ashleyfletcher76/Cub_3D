/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:17:50 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/01 11:54:56 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *string, ...);
int		print_unsigned(unsigned int n, int fd);
int		print_digit(int n, int fd);
int		print_pointer(void *ptr);
int		print_str(char *str, int fd);
int		print_hexa(unsigned long nbr, const char *base);

int		putchar_custom(char c, int fd);
int		putstr(char *str, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
