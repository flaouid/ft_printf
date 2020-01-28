#include "printf.h"
#include "libft.h"


/* Cette fonction recupere le nombre et le transforme en char*,
   dans la bonne base et avec les bonnes conversions.
*/

static void		check_base(char base[17], t_params *pr)
{
	if	(pr->type == 'x' || pr->type == 'p')
		ft_strcpy(base, "0123456789abcdef");
	else if (pr->type == 'X')
		ft_strcpy(base,"0123456789ABCDEF");
	else if (pr->type = 'o')
		ft_strcpy(base, "01234567");
	else
		ft_strcpy(base, "0123456789");
}
