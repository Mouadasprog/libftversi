/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:23:50 by mouad             #+#    #+#             */
/*   Updated: 2024/11/08 10:27:11 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  get_digit_count(int n, int base)
{
    int count = 0;
    if (n == 0)
        return 1;
    if (n < 0 && base == 10)
    {
        count++;
        n = -n;
    }
    while (n != 0)
    {
        count++;
        n /= base;
    }
    return count;
}

char *itoa(int n, int base)
{
    if (base < 2 || base > 16)
        return NULL;
    
    int len = get_digit_count(n, base);
    char *result = (char *)malloc(len + 1);
    
    if (!result)
        return NULL; 

    result[len] = '\0';

    if (n == 0)
    {
        result[0] = '0';
        return result;
    }

    int is_negative = 0;
    if (n < 0 && base == 10)
    {
        is_negative = 1;
        n = -n;
    }

    const char *digits = "0123456789ABCDEF";
    int i = len - 1;

    while (n != 0)
    {
        result[i--] = digits[n % base];
        n /= base;
    }

    if (is_negative)
        result[0] = '-';

    return result;
}