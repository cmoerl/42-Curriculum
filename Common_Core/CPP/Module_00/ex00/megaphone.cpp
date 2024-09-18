/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:25:55 by csturm            #+#    #+#             */
/*   Updated: 2024/09/18 13:36:01 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
            std::cout << static_cast<char>(toupper(argv[i][j]));
        if (i + 1 < argc)
            std::cout << " ";
    }
    std::cout << "\n";
    return (0);
}
