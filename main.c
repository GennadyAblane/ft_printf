/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:17:22 by ablane            #+#    #+#             */
/*   Updated: 2020/02/11 14:04:43 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int i;
	int p;
	int a;
	int b;
	char *w;
	unsigned long long int a01;
	int a02;
	int a03;
	int a04;
	int a05;
	int a06;
	int a07;
	int a08;
	int a09;
	int a10;
	int a11;
	int a12;


	a01 = 9223372036854775807;
	b = 13434536;
	w = "(%08.5d, -16)";
	write(1, "original printf\n", 16);
//	printf("%s", "sdg");
//	p = printf("[%15.8s][%s] [%-15.11s] eshe raz", NULL, "%015d", "shpilivili");

	p = printf("this [%.19f] float", 0.000000000000000000100);
	printf("\n");
	printf("\n");
	printf("%d", p);
	printf("\n");
	printf("\n");
	write(1, "my ft\n", 6);
//	i = ft_printf("[%15.8s][%s] [%-15.11s] eshe raz", NULL, "%015d",
//	"shpilivili");

	i = ft_printf("this [%.19f] float", 0.000000000000000000100);
	printf("\n");
	printf("%d", i);

	return (0);
}





//p = printf("%9d raza vseh shpilivili %6d eshe raz %d", 799, 123, 3);
//i = ft_printf("%9d raza vseh shpilivili %6d eshe raz %d", 799, 123, 3);