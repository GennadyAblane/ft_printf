cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 90)

add_executable(ft_printf main.c ft_printf.c ft_printf.h ft_halper.c func_c.c func_di.c func_percent.c func_s.c string_list.c func_p.c ft_find_flag.c ft_itoa_base.c func_o.c func_u.c func_x.c)
find_library(FT ft libft)
target_link_libraries(ft_printf LINK_PUBLIC ${FT})