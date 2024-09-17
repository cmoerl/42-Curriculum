/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:25:55 by csturm            #+#    #+#             */
/*   Updated: 2024/09/17 10:32:25 by csturm           ###   ########.fr       */
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
    for (int i = 1; argv[i] != NULL; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
            std::cout << static_cast<char>(toupper(argv[i][j]));
        if (argv[i + 1] != NULL)
            std::cout << " ";
    }
    std::cout << "\n";
    return (0);
}