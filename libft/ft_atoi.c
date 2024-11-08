/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:41:26 by mouad             #+#    #+#             */
/*   Updated: 2024/11/06 17:57:26 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	return (c == '\n' || c == '\v' || c == '\f' || c == '\t' || c == '\r'
		|| c == ' ');
}

int	ft_atoi(char *str)
{
	size_t i;
	unsigned long int results = 0;
	int sign = 1;
	i = 0;
	while (is_space(str[i]))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		results = results * 10 + (str[i] - '0');
		i++;
	}
	return (results * sign);
}
int main() {
    printf("Input: \"42\" -> ft_atoi result: %d\n", ft_atoi("42"));                   // Simple positive number
    printf("Input: \"-42\" -> ft_atoi result: %d\n", ft_atoi("-42"));                 // Simple negative number
    printf("Input: \"+42\" -> ft_atoi result: %d\n", ft_atoi("+42"));                 // Positive number with sign
    printf("Input: \"   42\" -> ft_atoi result: %d\n", ft_atoi("   42"));             // Leading whitespace
    printf("Input: \"   -42\" -> ft_atoi result: %d\n", ft_atoi("   -42"));           // Leading whitespace with negative
    printf("Input: \"42abc\" -> ft_atoi result: %d\n", ft_atoi("42abc"));             // Characters after number
    printf("Input: \"abc42\" -> ft_atoi result: %d\n", ft_atoi("abc42"));             // Characters before number
    printf("Input: \"12abc34\" -> ft_atoi result: %d\n", ft_atoi("12abc34"));         // Embedded characters within digits
    printf("Input: \"2147483647\" -> ft_atoi result: %d\n", ft_atoi("2147483647"));   // INT_MAX
    printf("Input: \"2147483648\" -> ft_atoi result: %d\n", ft_atoi("2147483648"));   // Overflow above INT_MAX
    printf("Input: \"-2147483648\" -> ft_atoi result: %d\n", ft_atoi("-2147483648")); // INT_MIN
    printf("Input: \"-2147483649\" -> ft_atoi result: %d\n", ft_atoi("-2147483649")); // Underflow below INT_MIN
    printf("Input: \"\" -> ft_atoi result: %d\n", ft_atoi(""));                       // Empty string
    printf("Input: \"+\" -> ft_atoi result: %d\n", ft_atoi("+"));                     // Only plus sign
    printf("Input: \"-\" -> ft_atoi result: %d\n", ft_atoi("-"));                     // Only minus sign
    printf("Input: \"00042\" -> ft_atoi result: %d\n", ft_atoi("00042"));             // Leading zeros
    printf("Input: \"   +00042\" -> ft_atoi result: %d\n", ft_atoi("   +00042"));     // Leading whitespace and zeros with plus sign
    printf("Input: \"9223372036854775807\" -> ft_atoi result: %d\n", ft_atoi("9223372036854775807"));   // Large number exceeding INT_MAX
    printf("Input: \"-9223372036854775808\" -> ft_atoi result: %d\n", ft_atoi("-9223372036854775808")); // Large negative number exceeding INT_MIN
    printf("Input: \"++42\" -> ft_atoi result: %d\n", ft_atoi("++42"));               // Invalid double positive sign
    printf("Input: \"--42\" -> ft_atoi result: %d\n", ft_atoi("--42"));               // Invalid double negative sign
    printf("Input: \"+-42\" -> ft_atoi result: %d\n", ft_atoi("+-42"));               // Mixed signs
    printf("Input: \"0\" -> ft_atoi result: %d\n", ft_atoi("0"));                     // Zero
    printf("Input: \"-0\" -> ft_atoi result: %d\n", ft_atoi("-0"));                   // Negative zero

    return 0;
}