#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = (char*)malloc(sizeof(size_t) * size);
	if (ptr)
	{
		ft_bzero(ptr, size);
		return (ptr);
	}
	return (NULL);
}
