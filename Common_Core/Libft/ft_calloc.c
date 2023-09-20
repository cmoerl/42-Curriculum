/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:39:47 by csturm            #+#    #+#             */
/*   Updated: 2023/09/20 16:25:58 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total;

	if (nmemb && SIZE_MAX / nmemb < size)
		return (0);
	mem = malloc(nmemb * size);
	if (!mem)
		return (0);
	total = nmemb * size;
	ft_bzero(mem, total);
	return (mem);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%p\n", ft_calloc(1234571234, 12354879));
	printf("%p\n", calloc(1234578965, 12345678));
	return (0);
}
*/
